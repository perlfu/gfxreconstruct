/*
** Copyright (c) 2018-2019 Valve Corporation
** Copyright (c) 2018-2019 LunarG, Inc.
** Copyright (c) 2019 Advanced Micro Devices, Inc. All rights reserved.
**
** Licensed under the Apache License, Version 2.0 (the "License");
** you may not use this file except in compliance with the License.
** You may obtain a copy of the License at
**
**     http://www.apache.org/licenses/LICENSE-2.0
**
** Unless required by applicable law or agreed to in writing, software
** distributed under the License is distributed on an "AS IS" BASIS,
** WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
** See the License for the specific language governing permissions and
** limitations under the License.
*/

#include "encode/trace_manager.h"

#include "encode/vulkan_handle_wrapper_util.h"
#include "encode/vulkan_state_writer.h"
#include "format/format_util.h"
#include "generated/generated_vulkan_struct_handle_wrappers.h"
#include "util/compressor.h"
#include "util/file_path.h"
#include "util/logging.h"
#include "util/page_guard_manager.h"
#include "util/platform.h"

#include <cassert>

#if defined(__linux__) && !defined(__ANDROID__)
#if defined(VK_USE_PLATFORM_XCB_KHR)
#include <xcb/xcb_keysyms.h>
#endif
#endif

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

// Default log level to use prior to loading settings.
const util::Log::Severity kDefaultLogLevel = util::Log::Severity::kInfoSeverity;

// One based frame count.
const uint32_t kFirstFrame = 1;

std::mutex                                     TraceManager::ThreadData::count_lock_;
format::ThreadId                               TraceManager::ThreadData::thread_count_ = 0;
std::unordered_map<uint64_t, format::ThreadId> TraceManager::ThreadData::id_map_;

TraceManager*                                          TraceManager::instance_       = nullptr;
uint32_t                                               TraceManager::instance_count_ = 0;
std::mutex                                             TraceManager::instance_lock_;
thread_local std::unique_ptr<TraceManager::ThreadData> TraceManager::thread_data_;
LayerTable                                             TraceManager::layer_table_;
std::atomic<format::ThreadId>                          TraceManager::unique_id_counter_{ 0 };
bool                                                   TraceManager::previous_hotkey_trigger_ = false;

TraceManager::ThreadData::ThreadData() : thread_id_(GetThreadId()), call_id_(format::ApiCallId::ApiCall_Unknown)
{
    parameter_buffer_  = std::make_unique<util::MemoryOutputStream>();
    parameter_encoder_ = std::make_unique<ParameterEncoder>(parameter_buffer_.get());
}

format::ThreadId TraceManager::ThreadData::GetThreadId()
{
    format::ThreadId id  = 0;
    uint64_t         tid = util::platform::GetCurrentThreadId();

    // Using a uint64_t sequence number associated with the thread ID.
    std::lock_guard<std::mutex> lock(count_lock_);
    auto                        entry = id_map_.find(tid);
    if (entry != id_map_.end())
    {
        id = entry->second;
    }
    else
    {
        id = ++thread_count_;
        id_map_.insert(std::make_pair(tid, id));
    }

    return id;
}

TraceManager::TraceManager() :
    force_file_flush_(false), bytes_written_(0), timestamp_filename_(true),
    memory_tracking_mode_(CaptureSettings::MemoryTrackingMode::kPageGuard), page_guard_external_memory_(false),
    trim_enabled_(false), trim_current_range_(0), current_frame_(kFirstFrame), capture_mode_(kModeWrite)
{}

TraceManager::~TraceManager()
{
    if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager::Destroy();
    }
}

void TraceManager::SetLayerFuncs(PFN_vkCreateInstance create_instance, PFN_vkCreateDevice create_device)
{
    assert((create_instance != nullptr) && (create_device != nullptr));
    layer_table_.CreateInstance = create_instance;
    layer_table_.CreateDevice   = create_device;
}

bool TraceManager::CreateInstance()
{
    bool                        success = true;
    std::lock_guard<std::mutex> instance_lock(instance_lock_);

    if (instance_count_ == 0)
    {
        assert(instance_ == nullptr);

        // Default initialize logging to report issues while loading settings.
        util::Log::Init(kDefaultLogLevel);

        CaptureSettings settings = {};
        CaptureSettings::LoadSettings(&settings);

        // Reinitialize logging with values retrieved from settings.
        const util::Log::Settings& log_settings = settings.GetLogSettings();
        util::Log::Release();
        util::Log::Init(log_settings);

        CaptureSettings::TraceSettings trace_settings = settings.GetTraceSettings();
        std::string                    base_filename  = trace_settings.capture_file;

        instance_count_ = 1;
        instance_       = new TraceManager();
        success         = instance_->Initialize(base_filename, trace_settings);
        if (!success)
        {
            GFXRECON_LOG_FATAL("Failed to initialize TraceManager");
        }
    }
    else
    {
        assert(instance_ != nullptr);
        ++instance_count_;
    }

    GFXRECON_LOG_DEBUG("vkCreateInstance(): Current instance count is %u", instance_count_);

    return success;
}

void TraceManager::CheckCreateInstanceStatus(VkResult result)
{
    if (result != VK_SUCCESS)
    {
        DestroyInstance();
    }
}

void TraceManager::DestroyInstance()
{
    std::lock_guard<std::mutex> instance_lock(instance_lock_);

    if (instance_ != nullptr)
    {
        assert(instance_count_ > 0);

        --instance_count_;

        if (instance_count_ == 0)
        {
            delete instance_;
            instance_ = nullptr;

            util::Log::Release();
        }

        GFXRECON_LOG_DEBUG("vkDestroyInstance(): Current instance count is %u", instance_count_);
    }
}

void TraceManager::InitInstance(VkInstance* instance, PFN_vkGetInstanceProcAddr gpa)
{
    assert(instance != nullptr);

    CreateWrappedHandle<NoParentWrapper, NoParentWrapper, InstanceWrapper>(
        NoParentWrapper::kHandleValue, NoParentWrapper::kHandleValue, instance, GetUniqueId);

    auto wrapper = reinterpret_cast<InstanceWrapper*>(*instance);
    LoadInstanceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

void TraceManager::InitDevice(VkDevice* device, PFN_vkGetDeviceProcAddr gpa)
{
    assert((device != nullptr) && ((*device) != VK_NULL_HANDLE));

    CreateWrappedHandle<PhysicalDeviceWrapper, NoParentWrapper, DeviceWrapper>(
        VK_NULL_HANDLE, NoParentWrapper::kHandleValue, device, GetUniqueId);

    auto wrapper = reinterpret_cast<DeviceWrapper*>(*device);
    LoadDeviceTable(gpa, wrapper->handle, &wrapper->layer_table);
}

bool TraceManager::Initialize(std::string base_filename, const CaptureSettings::TraceSettings& trace_settings)
{
    bool success = true;

    base_filename_        = base_filename;
    file_options_         = trace_settings.capture_file_options;
    timestamp_filename_   = trace_settings.time_stamp_file;
    memory_tracking_mode_ = trace_settings.memory_tracking_mode;
    force_file_flush_     = trace_settings.force_flush;

    if (memory_tracking_mode_ == CaptureSettings::kPageGuard)
    {
#if defined(WIN32)
        page_guard_external_memory_ = trace_settings.page_guard_external_memory;
#else
        page_guard_external_memory_ = false;
        if (trace_settings.page_guard_external_memory)
        {
            GFXRECON_LOG_WARNING("Ignoring page guard external memory option on unsupported platform (Only Windows is "
                                 "currently supported)")
        }
#endif
    }
    else
    {
        page_guard_external_memory_ = false;
    }

    if (trace_settings.trim_ranges.empty() && trace_settings.trim_key.empty())
    {
        // Use default kModeWrite capture mode.
        success = CreateCaptureFile(base_filename_);
    }
    else
    {
        // Override default kModeWrite capture mode.
        trim_enabled_ = true;
        trim_ranges_  = trace_settings.trim_ranges;

        // Determine if trim starts at the first frame
        if (!trace_settings.trim_ranges.empty())
        {
            trim_ranges_ = trace_settings.trim_ranges;
            if (trim_ranges_[0].first == current_frame_)
            {
                // When capturing from the first frame, state tracking only needs to be enabled if there is more than
                // one capture range.
                if (trim_ranges_.size() > 1)
                {
                    capture_mode_ = kModeWriteAndTrack;
                }

                success = CreateCaptureFile(CreateTrimFilename(base_filename_, trim_ranges_[0]));
            }
            else
            {
                capture_mode_ = kModeTrack;
            }
        }
        // Check if trim is enabled by hot-key trigger at the first frame
        else if (!trace_settings.trim_key.empty())
        {
            trim_key_ = trace_settings.trim_key;

            // Enable state tracking when hotkey pressed
            if (IsTrimHotkeyPressed())
            {
                capture_mode_ = kModeWriteAndTrack;

                success = CreateCaptureFile(util::filepath::InsertFilenamePostfix(base_filename_, "_trim_trigger"));
            }
            else
            {
                capture_mode_ = kModeTrack;
            }
        }
        else
        {
            capture_mode_ = kModeTrack;
        }
    }

    if (success)
    {
        compressor_ = std::unique_ptr<util::Compressor>(format::CreateCompressor(file_options_.compression_type));
        if ((nullptr == compressor_) && (format::CompressionType::kNone != file_options_.compression_type))
        {
            success = false;
        }
    }

    if (success)
    {
        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager::Create(!page_guard_external_memory_,
                                           trace_settings.page_guard_copy_on_map,
                                           trace_settings.page_guard_lazy_copy,
                                           trace_settings.page_guard_separate_read,
                                           util::PageGuardManager::kDefaultEnableReadWriteSamePage);
        }

        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            state_tracker_ = std::make_unique<VulkanStateTracker>();
        }
    }
    else
    {
        capture_mode_ = kModeDisabled;
    }

    return success;
}

ParameterEncoder* TraceManager::InitApiCallTrace(format::ApiCallId call_id)
{
    auto thread_data      = GetThreadData();
    thread_data->call_id_ = call_id;
    return thread_data->parameter_encoder_.get();
}

void TraceManager::EndApiCallTrace(ParameterEncoder* encoder)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        assert(encoder != nullptr);

        auto thread_data = GetThreadData();
        assert(thread_data != nullptr);

        auto parameter_buffer = thread_data->parameter_buffer_.get();
        assert((parameter_buffer != nullptr) && (thread_data->parameter_encoder_ != nullptr) &&
               (thread_data->parameter_encoder_.get() == encoder));

        bool                                 not_compressed      = true;
        format::CompressedFunctionCallHeader compressed_header   = {};
        format::FunctionCallHeader           uncompressed_header = {};
        size_t                               uncompressed_size   = parameter_buffer->GetDataSize();
        size_t                               header_size         = 0;
        const void*                          header_pointer      = nullptr;
        size_t                               data_size           = 0;
        const void*                          data_pointer        = nullptr;

        if (nullptr != compressor_)
        {
            size_t packet_size = 0;
            size_t compressed_size =
                compressor_->Compress(uncompressed_size, parameter_buffer->GetData(), &thread_data->compressed_buffer_);

            if ((0 < compressed_size) && (compressed_size < uncompressed_size))
            {
                data_pointer   = reinterpret_cast<const void*>(thread_data->compressed_buffer_.data());
                data_size      = compressed_size;
                header_pointer = reinterpret_cast<const void*>(&compressed_header);
                header_size    = sizeof(format::CompressedFunctionCallHeader);

                compressed_header.block_header.type = format::BlockType::kCompressedFunctionCallBlock;
                compressed_header.api_call_id       = thread_data->call_id_;
                compressed_header.thread_id         = thread_data->thread_id_;
                compressed_header.uncompressed_size = uncompressed_size;

                packet_size += sizeof(compressed_header.api_call_id) + sizeof(compressed_header.uncompressed_size) +
                               sizeof(compressed_header.thread_id) + compressed_size;

                compressed_header.block_header.size = packet_size;
                not_compressed                      = false;
            }
        }

        if (not_compressed)
        {
            size_t packet_size = 0;
            data_pointer       = reinterpret_cast<const void*>(parameter_buffer->GetData());
            data_size          = uncompressed_size;
            header_pointer     = reinterpret_cast<const void*>(&uncompressed_header);
            header_size        = sizeof(format::FunctionCallHeader);

            uncompressed_header.block_header.type = format::BlockType::kFunctionCallBlock;
            uncompressed_header.api_call_id       = thread_data->call_id_;
            uncompressed_header.thread_id         = thread_data->thread_id_;

            packet_size += sizeof(uncompressed_header.api_call_id) + sizeof(uncompressed_header.thread_id) + data_size;

            uncompressed_header.block_header.size = packet_size;
        }

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            // Write appropriate function call block header.
            bytes_written_ += file_stream_->Write(header_pointer, header_size);

            // Write parameter data.
            bytes_written_ += file_stream_->Write(data_pointer, data_size);

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }

        encoder->Reset();
    }
    else if (encoder != nullptr)
    {
        encoder->Reset();
    }
}

#if defined(__linux__) && !defined(__ANDROID__)
#if defined(VK_USE_PLATFORM_XCB_KHR)
static xcb_connection_t* keyboard_connection = nullptr;

// On Linux platform, xcb calls need Connection which is connected to target
// server, because hotkey process is supposed to insert into target application,
// so we need to capture the connection that target app use. the function is
// used to insert into Vulkan vkCreateXcbSurfaceKHR call to capture and
// save the connection.
static void SetKeyboardConnection(xcb_connection_t* connection)
{
    keyboard_connection = connection;
}

// Get connection which is used by target application.
static xcb_connection_t* GetKeyboardConnection()
{
    return keyboard_connection;
}

// Get specified key's real time state: it's released (0) or pressed (1) now.
// the function is platform specific.
static int GetAsyncKeyState(int key_code)
{
    int                key_state      = 0;
    xcb_connection_t*  connection     = GetKeyboardConnection();
    xcb_key_symbols_t* hot_key_symbol = xcb_key_symbols_alloc(connection);
    if (hot_key_symbol != nullptr)
    {
        xcb_keycode_t* xcb_key_code = xcb_key_symbols_get_keycode(hot_key_symbol, key_code);
        if (xcb_key_code != nullptr)
        {
            xcb_query_keymap_cookie_t cookie       = xcb_query_keymap(connection);
            xcb_query_keymap_reply_t* keys_bit_map = xcb_query_keymap_reply(connection, cookie, NULL);
            if ((keys_bit_map->keys[(*xcb_key_code / 8)] & (1 << (*xcb_key_code % 8))) != 0)
            {
                key_state = 1;
            }
            free(keys_bit_map);
            free(xcb_key_code);
        }
        xcb_key_symbols_free(hot_key_symbol);
    }

    return key_state;
}
#else
// TODO(issue #272) GetAsyncKeyState for other Linux window systems
static int GetAsyncKeyState(int key_code)
{
    GFXRECON_LOG_ERROR("Hotkey trigger is not supported for the current WSI platform.");
    return 0;
}
#endif
#elif defined(__ANDROID__)
// TODO(issue #272) implement GetAsyncKeyState for Android
// return 0 if hotkey not pressed
// return 1 if hotkey pressed
static int GetAsyncKeyState(int key_code)
{
    GFXRECON_LOG_ERROR("Hotkey trigger is not supported in Android yet.");
    return 0;
}
#endif

// Return true if specific key has been pressed, else false.
// This function is "semi"cross-platform: the interface is cross-platform, the
// implementation is platform specific.
bool TraceManager::IsTrimHotkeyPressed()
{
#ifdef _WIN32
    static std::unordered_map<std::string, int> key_code_map = {
        { "F1", VK_F1 },   { "F2", VK_F2 },   { "F3", VK_F3 },   { "F4", VK_F4 },          { "F5", VK_F5 },
        { "F6", VK_F6 },   { "F7", VK_F7 },   { "F8", VK_F8 },   { "F9", VK_F9 },          { "F10", VK_F10 },
        { "F11", VK_F11 }, { "F12", VK_F12 }, { "TAB", VK_TAB }, { "CONTROL", VK_CONTROL }
    };
#elif defined(__linux__) && !defined(__ANDROID__)
#if defined(VK_USE_PLATFORM_XCB_KHR)
    static std::unordered_map<std::string, int> key_code_map = { { "F1", XK_F1 },
                                                                 { "F2", XK_F2 },
                                                                 { "F3", XK_F3 },
                                                                 { "F4", XK_F4 },
                                                                 { "F5", XK_F5 },
                                                                 { "F6", XK_F6 },
                                                                 { "F7", XK_F7 },
                                                                 { "F8", XK_F8 },
                                                                 { "F9", XK_F9 },
                                                                 { "F10", XK_F10 },
                                                                 { "F11", XK_F11 },
                                                                 { "F12", XK_F12 },
                                                                 { "Tab", XK_Tab },
                                                                 { "ControlLeft", XK_Control_L },
                                                                 { "ControlRight", XK_Control_R } };
#else
    // TODO(issue #272) implement key_code_map for other Linux window systems
    static std::unordered_map<std::string, int> key_code_map = {};
#endif
#elif defined(__ANDROID__)
    // TODO(issue #272) implement key_code_map for Android
    static std::unordered_map<std::string, int> key_code_map = {};
#endif

    bool hotkey_triggered  = false;
    auto iterator_key_code = key_code_map.find(trim_key_);
    if (iterator_key_code != key_code_map.end())
    {
        int key_code = iterator_key_code->second;
        if (GetAsyncKeyState(key_code) != 0)
        {
            // the key is down or was down
            // after the previous call to
            // GetAsyncKeyState
            hotkey_triggered = true;

            // detect only the transition of the keypress event
            // in case of oversampling issue
            if (previous_hotkey_trigger_ == hotkey_triggered)
            {
                hotkey_triggered = false;
            }
            previous_hotkey_trigger_ = true;
        }
        else
        {
            previous_hotkey_trigger_ = false;
        }
    }

    return hotkey_triggered;
}

void TraceManager::CheckContinueCaptureForWriteMode()
{
    if (!trim_ranges_.empty())
    {
        --trim_ranges_[trim_current_range_].total;
        if (trim_ranges_[trim_current_range_].total == 0)
        {
            // Stop recording and close file.
            capture_mode_ &= ~kModeWrite;
            file_stream_ = nullptr;
            GFXRECON_LOG_INFO("Finished recording graphics API capture");

            // Advance to next range
            ++trim_current_range_;
            if (trim_current_range_ >= trim_ranges_.size())
            {
                // No more frames to capture. Capture can be disabled and resources can be released.
                trim_enabled_  = false;
                capture_mode_  = kModeDisabled;
                state_tracker_ = nullptr;
                compressor_    = nullptr;
            }
            else if (trim_ranges_[trim_current_range_].first == current_frame_)
            {
                // Trimming was configured to capture two consecutive frames, so we need to start a new capture
                // file for the current frame.
                const CaptureSettings::TrimRange& trim_range = trim_ranges_[trim_current_range_];
                bool success = CreateCaptureFile(CreateTrimFilename(base_filename_, trim_range));
                if (success)
                {
                    ActivateTrimming();
                }
                else
                {
                    GFXRECON_LOG_FATAL("Failed to initialize capture for trim range; capture has been disabled");
                    trim_enabled_ = false;
                    capture_mode_ = kModeDisabled;
                }
            }
        }
    }
    else if (IsTrimHotkeyPressed())
    {
        // Stop recording and close file.
        capture_mode_ &= ~kModeWrite;
        file_stream_ = nullptr;
        GFXRECON_LOG_INFO("Finished recording graphics API capture");
    }
}

void TraceManager::CheckStartCaptureForTrackMode()
{
    if (!trim_ranges_.empty())
    {
        if (trim_ranges_[trim_current_range_].first == current_frame_)
        {
            const CaptureSettings::TrimRange& trim_range = trim_ranges_[trim_current_range_];
            bool success = CreateCaptureFile(CreateTrimFilename(base_filename_, trim_range));
            if (success)
            {
                ActivateTrimming();
            }
            else
            {
                GFXRECON_LOG_FATAL("Failed to initialize capture for trim range; capture has been disabled");
                trim_enabled_ = false;
                capture_mode_ = kModeDisabled;
            }
        }
    }
    else if (IsTrimHotkeyPressed())
    {
        bool success = CreateCaptureFile(util::filepath::InsertFilenamePostfix(base_filename_, "_trim_trigger"));
        if (success)
        {
            ActivateTrimming();
        }
        else
        {
            GFXRECON_LOG_FATAL("Failed to initialize capture for hotkey trim trigger; capture has been disabled");
            trim_enabled_ = false;
            capture_mode_ = kModeDisabled;
        }
    }
}

void TraceManager::EndFrame()
{
    if (trim_enabled_)
    {
        ++current_frame_;

        if ((capture_mode_ & kModeWrite) == kModeWrite)
        {
            // Currently capturing a frame range.
            // Check for end of range or hotkey trigger to stop capture.
            CheckContinueCaptureForWriteMode();
        }
        else if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            // Capture is not active.
            // Check for start of capture frame range or hotkey trigger to start capture
            CheckStartCaptureForTrackMode();
        }
    }
}

std::string TraceManager::CreateTrimFilename(const std::string&                base_filename,
                                             const CaptureSettings::TrimRange& trim_range)
{
    assert(trim_range.total > 0);

    std::string range_string = "_";

    if (trim_range.total == 1)
    {
        range_string += "frame_";
        range_string += std::to_string(trim_range.first);
    }
    else
    {
        range_string += "frames_";
        range_string += std::to_string(trim_range.first);
        range_string += "_through_";
        range_string += std::to_string((trim_range.first + trim_range.total) - 1);
    }

    return util::filepath::InsertFilenamePostfix(base_filename, range_string);
}

bool TraceManager::CreateCaptureFile(const std::string& base_filename)
{
    bool        success          = true;
    std::string capture_filename = base_filename;

    if (timestamp_filename_)
    {
        capture_filename = util::filepath::GenerateTimestampedFilename(capture_filename);
    }

    file_stream_ = std::make_unique<util::FileOutputStream>(capture_filename);

    if (file_stream_->IsValid())
    {
        GFXRECON_LOG_INFO("Recording graphics API capture to %s", capture_filename.c_str());
        WriteFileHeader();
    }
    else
    {
        file_stream_ = nullptr;
        success      = false;
    }

    return success;
}

void TraceManager::ActivateTrimming()
{
    std::lock_guard<std::mutex> lock(file_lock_);

    capture_mode_ |= kModeWrite;

    auto thread_data = GetThreadData();
    assert(thread_data != nullptr);

    VulkanStateWriter state_writer(file_stream_.get(), compressor_.get(), thread_data->thread_id_);
    state_tracker_->WriteState(&state_writer, current_frame_);
}

void TraceManager::WriteFileHeader()
{
    std::vector<format::FileOptionPair> option_list;

    BuildOptionList(file_options_, &option_list);

    format::FileHeader file_header;
    file_header.fourcc        = GFXRECON_FOURCC;
    file_header.major_version = 0;
    file_header.minor_version = 0;
    file_header.num_options   = static_cast<uint32_t>(option_list.size());

    bytes_written_ += file_stream_->Write(&file_header, sizeof(file_header));
    bytes_written_ += file_stream_->Write(option_list.data(), option_list.size() * sizeof(format::FileOptionPair));

    if (force_file_flush_)
    {
        file_stream_->Flush();
    }
}

void TraceManager::BuildOptionList(const format::EnabledOptions&        enabled_options,
                                   std::vector<format::FileOptionPair>* option_list)
{
    assert(option_list != nullptr);

    option_list->push_back({ format::FileOption::kCompressionType, enabled_options.compression_type });
}

void TraceManager::WriteDisplayMessageCmd(const char* message)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        size_t                              message_length = util::platform::StringLength(message);
        format::DisplayMessageCommandHeader message_cmd;

        message_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        message_cmd.meta_header.block_header.size =
            sizeof(message_cmd.meta_header.meta_data_type) + sizeof(message_cmd.thread_id) + message_length;
        message_cmd.meta_header.meta_data_type = format::MetaDataType::kDisplayMessageCommand;
        message_cmd.thread_id                  = GetThreadData()->thread_id_;

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            bytes_written_ += file_stream_->Write(&message_cmd, sizeof(message_cmd));
            bytes_written_ += file_stream_->Write(message, message_length);

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }
    }
}

void TraceManager::WriteResizeWindowCmd(format::HandleId surface_id, uint32_t width, uint32_t height)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        format::ResizeWindowCommand resize_cmd;
        resize_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        resize_cmd.meta_header.block_header.size = sizeof(resize_cmd.meta_header.meta_data_type) +
                                                   sizeof(resize_cmd.thread_id) + sizeof(resize_cmd.surface_id) +
                                                   sizeof(resize_cmd.width) + sizeof(resize_cmd.height);
        resize_cmd.meta_header.meta_data_type = format::MetaDataType::kResizeWindowCommand;
        resize_cmd.thread_id                  = GetThreadData()->thread_id_;

        resize_cmd.surface_id = surface_id;
        resize_cmd.width      = width;
        resize_cmd.height     = height;

        {
            std::lock_guard<std::mutex> lock(file_lock_);
            bytes_written_ += file_stream_->Write(&resize_cmd, sizeof(resize_cmd));

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }
    }
}

void TraceManager::WriteFillMemoryCmd(format::HandleId memory_id,
                                      VkDeviceSize     offset,
                                      VkDeviceSize     size,
                                      const void*      data)
{
    if ((capture_mode_ & kModeWrite) == kModeWrite)
    {
        GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

        format::FillMemoryCommandHeader fill_cmd;
        const uint8_t*                  write_address = (static_cast<const uint8_t*>(data) + offset);
        size_t                          write_size    = static_cast<size_t>(size);

        fill_cmd.meta_header.block_header.type = format::BlockType::kMetaDataBlock;
        fill_cmd.meta_header.meta_data_type    = format::MetaDataType::kFillMemoryCommand;
        fill_cmd.thread_id                     = GetThreadData()->thread_id_;
        fill_cmd.memory_id                     = memory_id;
        fill_cmd.memory_offset                 = offset;
        fill_cmd.memory_size                   = size;

        if (compressor_ != nullptr)
        {
            auto thread_data = GetThreadData();
            assert(thread_data != nullptr);

            size_t compressed_size = compressor_->Compress(write_size, write_address, &thread_data->compressed_buffer_);

            if ((compressed_size > 0) && (compressed_size < write_size))
            {
                // We don't have a special header for compressed fill commands because the header always includes
                // the uncompressed size, so we just change the type to indicate the data is compressed.
                fill_cmd.meta_header.block_header.type = format::BlockType::kCompressedMetaDataBlock;

                write_address = thread_data->compressed_buffer_.data();
                write_size    = compressed_size;
            }
        }

        // Calculate size of packet with compressed or uncompressed data size.
        fill_cmd.meta_header.block_header.size =
            sizeof(fill_cmd.meta_header.meta_data_type) + sizeof(fill_cmd.thread_id) + sizeof(fill_cmd.memory_id) +
            sizeof(fill_cmd.memory_offset) + sizeof(fill_cmd.memory_size) + write_size;

        {
            std::lock_guard<std::mutex> lock(file_lock_);

            bytes_written_ += file_stream_->Write(&fill_cmd, sizeof(fill_cmd));
            bytes_written_ += file_stream_->Write(write_address, write_size);

            if (force_file_flush_)
            {
                file_stream_->Flush();
            }
        }
    }
}

void TraceManager::SetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate                  update_template,
                                                   const VkDescriptorUpdateTemplateCreateInfo* create_info)
{
    // A NULL check should have been performed by the caller.
    assert((create_info != nullptr));

    if (create_info->descriptorUpdateEntryCount > 0)
    {
        DescriptorUpdateTemplateWrapper* wrapper = reinterpret_cast<DescriptorUpdateTemplateWrapper*>(update_template);
        UpdateTemplateInfo*              info    = &wrapper->info;

        for (size_t i = 0; i < create_info->descriptorUpdateEntryCount; ++i)
        {
            const VkDescriptorUpdateTemplateEntry* entry      = &create_info->pDescriptorUpdateEntries[i];
            VkDescriptorType                       type       = entry->descriptorType;
            size_t                                 entry_size = 0;

            // Sort the descriptor update template info by type, so it can be written to the capture file
            // as tightly packed arrays of structures.  One array will be written for each descriptor info
            // structure/textel buffer view.
            if ((type == VK_DESCRIPTOR_TYPE_SAMPLER) || (type == VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER) ||
                (type == VK_DESCRIPTOR_TYPE_SAMPLED_IMAGE) || (type == VK_DESCRIPTOR_TYPE_STORAGE_IMAGE) ||
                (type == VK_DESCRIPTOR_TYPE_INPUT_ATTACHMENT))
            {
                UpdateTemplateEntryInfo image_info;
                image_info.binding       = entry->dstBinding;
                image_info.array_element = entry->dstArrayElement;
                image_info.count         = entry->descriptorCount;
                image_info.offset        = entry->offset;
                image_info.stride        = entry->stride;
                image_info.type          = type;

                info->image_info_count += entry->descriptorCount;
                info->image_info.emplace_back(image_info);

                entry_size = sizeof(VkDescriptorImageInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER) || (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER_DYNAMIC) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_BUFFER_DYNAMIC))
            {
                UpdateTemplateEntryInfo buffer_info;
                buffer_info.binding       = entry->dstBinding;
                buffer_info.array_element = entry->dstArrayElement;
                buffer_info.count         = entry->descriptorCount;
                buffer_info.offset        = entry->offset;
                buffer_info.stride        = entry->stride;
                buffer_info.type          = type;

                info->buffer_info_count += entry->descriptorCount;
                info->buffer_info.emplace_back(buffer_info);

                entry_size = sizeof(VkDescriptorBufferInfo);
            }
            else if ((type == VK_DESCRIPTOR_TYPE_UNIFORM_TEXEL_BUFFER) ||
                     (type == VK_DESCRIPTOR_TYPE_STORAGE_TEXEL_BUFFER))
            {
                UpdateTemplateEntryInfo texel_buffer_view_info;
                texel_buffer_view_info.binding       = entry->dstBinding;
                texel_buffer_view_info.array_element = entry->dstArrayElement;
                texel_buffer_view_info.count         = entry->descriptorCount;
                texel_buffer_view_info.offset        = entry->offset;
                texel_buffer_view_info.stride        = entry->stride;
                texel_buffer_view_info.type          = type;

                info->texel_buffer_view_count += entry->descriptorCount;
                info->texel_buffer_view.emplace_back(texel_buffer_view_info);

                entry_size = sizeof(VkBufferView);
            }
            else
            {
                GFXRECON_LOG_ERROR("Unrecognized/unsupported descriptor type in descriptor update template.");
                assert(false);
            }

            if (entry->descriptorCount > 0)
            {
                size_t max_size = ((entry->descriptorCount - 1) * entry->stride) + entry->offset + entry_size;
                if (max_size > info->max_size)
                {
                    info->max_size = max_size;
                }
            }
        }
    }
}

bool TraceManager::GetDescriptorUpdateTemplateInfo(VkDescriptorUpdateTemplate update_template,
                                                   const UpdateTemplateInfo** info) const
{
    assert(info != nullptr);

    bool found = false;

    if (update_template != VK_NULL_HANDLE)
    {
        DescriptorUpdateTemplateWrapper* wrapper = reinterpret_cast<DescriptorUpdateTemplateWrapper*>(update_template);

        (*info) = &wrapper->info;
        found   = true;
    }

    return found;
}

void TraceManager::TrackUpdateDescriptorSetWithTemplate(VkDescriptorSet            set,
                                                        VkDescriptorUpdateTemplate update_template,
                                                        const void*                data)
{
    const UpdateTemplateInfo* info = nullptr;
    if (GetDescriptorUpdateTemplateInfo(update_template, &info))
    {
        assert(state_tracker_ != nullptr);
        state_tracker_->TrackUpdateDescriptorSetWithTemplate(set, info, data);
    }
}

VkResult TraceManager::OverrideCreateInstance(const VkInstanceCreateInfo*  pCreateInfo,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkInstance*                  pInstance)
{
    VkResult result = VK_ERROR_INITIALIZATION_FAILED;

    if (CreateInstance())
    {
        if (instance_->page_guard_external_memory_)
        {
            assert(pCreateInfo != nullptr);

            VkInstanceCreateInfo create_info_copy = (*pCreateInfo);

            // TODO: Only enable KHR_get_physical_device_properties_2 for 1.0 API version.
            size_t                   extension_count = create_info_copy.enabledExtensionCount;
            const char* const*       extensions      = create_info_copy.ppEnabledExtensionNames;
            std::vector<const char*> modified_extensions;

            bool has_dev_prop2 = false;

            for (size_t i = 0; i < extension_count; ++i)
            {
                auto entry = extensions[i];

                modified_extensions.push_back(entry);

                if (util::platform::StringCompare(entry, VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME) == 0)
                {
                    has_dev_prop2 = true;
                }
            }

            if (!has_dev_prop2)
            {
                modified_extensions.push_back(VK_KHR_GET_PHYSICAL_DEVICE_PROPERTIES_2_EXTENSION_NAME);
            }

            create_info_copy.enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
            create_info_copy.ppEnabledExtensionNames = modified_extensions.data();

            result = layer_table_.CreateInstance(&create_info_copy, pAllocator, pInstance);
        }
        else
        {
            result = layer_table_.CreateInstance(pCreateInfo, pAllocator, pInstance);
        }
    }

    return result;
}

VkResult TraceManager::OverrideCreateDevice(VkPhysicalDevice             physicalDevice,
                                            const VkDeviceCreateInfo*    pCreateInfo,
                                            const VkAllocationCallbacks* pAllocator,
                                            VkDevice*                    pDevice)
{
    auto                handle_unwrap_memory     = TraceManager::Get()->GetHandleUnwrapMemory();
    VkPhysicalDevice    physicalDevice_unwrapped = GetWrappedHandle<VkPhysicalDevice>(physicalDevice);
    VkDeviceCreateInfo* pCreateInfo_unwrapped =
        const_cast<VkDeviceCreateInfo*>(UnwrapStructPtrHandles(pCreateInfo, handle_unwrap_memory));

    if (page_guard_external_memory_)
    {
        assert(pCreateInfo_unwrapped != nullptr);

        // TODO: Only enable KHR_external_memory_capabilities for 1.0 API version.
        size_t                   extension_count = pCreateInfo_unwrapped->enabledExtensionCount;
        const char* const*       extensions      = pCreateInfo_unwrapped->ppEnabledExtensionNames;
        std::vector<const char*> modified_extensions;

        bool has_ext_mem_caps = false;
        bool has_ext_mem      = false;
        bool has_ext_mem_host = false;

        for (size_t i = 0; i < extension_count; ++i)
        {
            auto entry = pCreateInfo_unwrapped->ppEnabledExtensionNames[i];

            modified_extensions.push_back(entry);

            if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME) == 0)
            {
                has_ext_mem_caps = true;
            }
            else if (util::platform::StringCompare(entry, VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME) == 0)
            {
                has_ext_mem = true;
            }
            else if (util::platform::StringCompare(entry, VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME) == 0)
            {
                has_ext_mem_host = true;
            }
        }

        if (!has_ext_mem_caps)
        {
            modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_CAPABILITIES_EXTENSION_NAME);
        }

        if (!has_ext_mem)
        {
            modified_extensions.push_back(VK_KHR_EXTERNAL_MEMORY_EXTENSION_NAME);
        }

        if (!has_ext_mem_host)
        {
            modified_extensions.push_back(VK_EXT_EXTERNAL_MEMORY_HOST_EXTENSION_NAME);
        }

        pCreateInfo_unwrapped->enabledExtensionCount   = static_cast<uint32_t>(modified_extensions.size());
        pCreateInfo_unwrapped->ppEnabledExtensionNames = modified_extensions.data();

        VkResult result =
            layer_table_.CreateDevice(physicalDevice_unwrapped, pCreateInfo_unwrapped, pAllocator, pDevice);

        if ((result == VK_SUCCESS) && (capture_mode_ & kModeTrack) != kModeTrack)
        {
            assert((pDevice != nullptr) && (*pDevice != VK_NULL_HANDLE));

            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set
            // here to ensure it is available for memory allocation.
            auto wrapper             = reinterpret_cast<DeviceWrapper*>(*pDevice);
            wrapper->physical_device = reinterpret_cast<PhysicalDeviceWrapper*>(physicalDevice);
        }

        return result;
    }
    else
    {
        return layer_table_.CreateDevice(physicalDevice_unwrapped, pCreateInfo_unwrapped, pAllocator, pDevice);
    }
}

VkResult TraceManager::OverrideAllocateMemory(VkDevice                     device,
                                              const VkMemoryAllocateInfo*  pAllocateInfo,
                                              const VkAllocationCallbacks* pAllocator,
                                              VkDeviceMemory*              pMemory)
{
    VkResult                         result          = VK_SUCCESS;
    void*                            external_memory = nullptr;
    VkImportMemoryHostPointerInfoEXT import_info;

    auto                  handle_unwrap_memory = TraceManager::Get()->GetHandleUnwrapMemory();
    VkDevice              device_unwrapped     = GetWrappedHandle<VkDevice>(device);
    VkMemoryAllocateInfo* pAllocateInfo_unwrapped =
        const_cast<VkMemoryAllocateInfo*>(UnwrapStructPtrHandles(pAllocateInfo, handle_unwrap_memory));

    if (page_guard_external_memory_)
    {
        auto                  device_wrapper = reinterpret_cast<DeviceWrapper*>(device);
        VkMemoryPropertyFlags properties     = GetMemoryProperties(device_wrapper, pAllocateInfo->memoryTypeIndex);

        if ((properties & VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT) == VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT)
        {
            // Use the external memory extension to provide a memory allocation that can be watched directly by the page
            // guard implementation.
            assert(pAllocateInfo_unwrapped != nullptr);

            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, pAllocateInfo_unwrapped->allocationSize);

            // TODO: This should be aligned to minImportedHostPointerAlignment, but there is a currently a loader bug
            // that prevents the layer from querying for that value when a 1.0 application does not explicitly enable
            // physical_device_properties2.  For now we align to system page size.
            size_t external_memory_size =
                manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo_unwrapped->allocationSize));
            external_memory = manager->AllocateMemory(external_memory_size);

            if (external_memory != nullptr)
            {
                pAllocateInfo_unwrapped->allocationSize = external_memory_size;

                import_info.sType        = VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT;
                import_info.pNext        = nullptr;
                import_info.handleType   = VK_EXTERNAL_MEMORY_HANDLE_TYPE_HOST_ALLOCATION_BIT_EXT;
                import_info.pHostPointer = external_memory;

                // TODO: Check pNext chain for use of incompatible extension types.
                VkBaseOutStructure* end = reinterpret_cast<VkBaseOutStructure*>(pAllocateInfo_unwrapped);
                while (end->pNext != nullptr)
                {
                    end = end->pNext;
                }

                end->pNext = reinterpret_cast<VkBaseOutStructure*>(&import_info);
            }
        }
    }

    result = GetDeviceTable(device)->AllocateMemory(device_unwrapped, pAllocateInfo_unwrapped, pAllocator, pMemory);

    if (result == VK_SUCCESS)
    {
        CreateWrappedHandle<DeviceWrapper, NoParentWrapper, DeviceMemoryWrapper>(
            device, NoParentWrapper::kHandleValue, pMemory, TraceManager::GetUniqueId);

        assert(pMemory != nullptr);
        auto memory_wrapper = reinterpret_cast<DeviceMemoryWrapper*>(*pMemory);

        memory_wrapper->external_allocation = external_memory;

        if ((capture_mode_ & kModeTrack) != kModeTrack)
        {
            // The state tracker will set this value when it is enabled. When state tracking is disabled it is set
            // here to ensure it is available for mapped memory tracking.
            auto wrapper             = reinterpret_cast<DeviceMemoryWrapper*>(*pMemory);
            wrapper->allocation_size = pAllocateInfo->allocationSize;
        }
    }
    else if (external_memory != nullptr)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(pAllocateInfo->allocationSize));
        manager->FreeMemory(external_memory, external_memory_size);
    }

    return result;
}

VkMemoryPropertyFlags TraceManager::GetMemoryProperties(DeviceWrapper* device_wrapper, uint32_t memory_type_index)
{
    VkMemoryPropertyFlags  flags                   = 0;
    PhysicalDeviceWrapper* physical_device_wrapper = device_wrapper->physical_device;

    if (memory_type_index >= physical_device_wrapper->memory_types.size())
    {
        // When trimming is enabled, the state tracker would populate this list when the application queried for
        // available memory types.  If state tracking is not enabled, or the application didn't make the appropriate
        // query, the query is made here.
        InstanceTable* instance_table = physical_device_wrapper->layer_table_ref;
        assert(instance_table != nullptr);

        VkPhysicalDeviceMemoryProperties memory_properties;
        instance_table->GetPhysicalDeviceMemoryProperties(physical_device_wrapper->handle, &memory_properties);

        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackPhysicalDeviceMemoryProperties(
                reinterpret_cast<VkPhysicalDevice>(physical_device_wrapper), &memory_properties);
            assert(memory_type_index < physical_device_wrapper->memory_types.size());
        }
        else
        {
            for (size_t i = 0; i < memory_properties.memoryTypeCount; ++i)
            {
                physical_device_wrapper->memory_types.push_back(memory_properties.memoryTypes[i]);
            }
        }
    }

    assert(memory_type_index < physical_device_wrapper->memory_types.size());

    return flags = physical_device_wrapper->memory_types[memory_type_index].propertyFlags;
}

void TraceManager::PreProcess_vkCreateXcbSurfaceKHR(VkInstance                       instance,
                                                    const VkXcbSurfaceCreateInfoKHR* pCreateInfo,
                                                    const VkAllocationCallbacks*     pAllocator,
                                                    VkSurfaceKHR*                    pSurface)
{
    GFXRECON_UNREFERENCED_PARAMETER(instance);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSurface);

#if defined(VK_USE_PLATFORM_XCB_KHR)
    assert(pCreateInfo != nullptr);
    if (pCreateInfo)
    {
        SetKeyboardConnection(pCreateInfo->connection);
    }
#else
    GFXRECON_UNREFERENCED_PARAMETER(pCreateInfo);
#endif
}

void TraceManager::PreProcess_vkCreateSwapchain(VkDevice                        device,
                                                const VkSwapchainCreateInfoKHR* pCreateInfo,
                                                const VkAllocationCallbacks*    pAllocator,
                                                VkSwapchainKHR*                 pSwapchain)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);
    GFXRECON_UNREFERENCED_PARAMETER(pSwapchain);

    assert(pCreateInfo != nullptr);

    if (pCreateInfo)
    {
        WriteResizeWindowCmd(
            GetWrappedId(pCreateInfo->surface), pCreateInfo->imageExtent.width, pCreateInfo->imageExtent.height);
    }
}

void TraceManager::PostProcess_vkMapMemory(VkResult         result,
                                           VkDevice         device,
                                           VkDeviceMemory   memory,
                                           VkDeviceSize     offset,
                                           VkDeviceSize     size,
                                           VkMemoryMapFlags flags,
                                           void**           ppData)
{
    if ((result == VK_SUCCESS) && (ppData != nullptr))
    {
        auto wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);
        assert(wrapper != nullptr);

        if (wrapper->mapped_data == nullptr)
        {
            if ((capture_mode_ & kModeTrack) == kModeTrack)
            {
                assert(state_tracker_ != nullptr);
                state_tracker_->TrackMappedMemory(device, memory, (*ppData), offset, size, flags);
            }
            else
            {
                // Perform subset of the state tracking performed by VulkanStateTracker::TrackMappedMemory, only storing
                // values needed for non-tracking capture.
                wrapper->mapped_data   = (*ppData);
                wrapper->mapped_offset = offset;
                wrapper->mapped_size   = size;
            }

            if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
            {
                if (size == VK_WHOLE_SIZE)
                {
                    size = wrapper->allocation_size;
                }

                if (size > 0)
                {
                    GFXRECON_CHECK_CONVERSION_DATA_LOSS(size_t, size);

                    util::PageGuardManager* manager = util::PageGuardManager::Get();
                    assert(manager != nullptr);

                    // Return the pointer provided by the pageguard manager, which may be a pointer to shadow memory,
                    // not the mapped memory.
                    (*ppData) = manager->AddMemory(wrapper->handle_id, (*ppData), static_cast<size_t>(size));
                }
            }
            else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
            {
                // Need to keep track of mapped memory objects so memory content can be written at queue submit.
                std::lock_guard<std::mutex> lock(mapped_memory_lock_);
                mapped_memory_.insert(wrapper);
            }
        }
        else
        {
            // The application has mapped the same VkDeviceMemory object more than once and the pageguard
            // manager is already tracking it, so we will return the pointer obtained from the pageguard manager
            // on the first map call.
            GFXRECON_LOG_WARNING("VkDeviceMemory object with handle = %" PRIx64 " has been mapped more than once",
                                 memory);

            if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
            {
                assert((wrapper->mapped_offset == offset) && (wrapper->mapped_size == size));

                // Return the shadow memory that was allocated for the previous map operation.
                util::PageGuardManager* manager = util::PageGuardManager::Get();
                assert(manager != nullptr);

                if (!manager->GetMemory(wrapper->handle_id, ppData))
                {
                    GFXRECON_LOG_ERROR("Modifications to the VkDeviceMemory object that has been mapped more than once "
                                       "are not being track by PageGuardManager");
                }
            }
        }
    }
}

void TraceManager::PreProcess_vkFlushMappedMemoryRanges(VkDevice                   device,
                                                        uint32_t                   memoryRangeCount,
                                                        const VkMappedMemoryRange* pMemoryRanges)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);

    if (pMemoryRanges != nullptr)
    {
        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            const DeviceMemoryWrapper* current_memory_wrapper = nullptr;
            util::PageGuardManager*    manager                = util::PageGuardManager::Get();
            assert(manager != nullptr);

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                auto next_memory_wrapper = reinterpret_cast<const DeviceMemoryWrapper*>(pMemoryRanges[i].memory);

                // Currently processing all dirty pages for the mapped memory, so filter multiple ranges from the same
                // object.
                if (next_memory_wrapper != current_memory_wrapper)
                {
                    current_memory_wrapper = next_memory_wrapper;

                    if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                    {
                        manager->ProcessMemoryEntry(
                            current_memory_wrapper->handle_id,
                            [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                WriteFillMemoryCmd(memory_id, offset, size, start_address);
                            });
                    }
                    else
                    {
                        GFXRECON_LOG_WARNING("vkFlushMappedMemoryRanges called for memory that is not mapped");
                    }
                }
            }
        }
        else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kAssisted)
        {
            const DeviceMemoryWrapper* current_memory_wrapper = nullptr;

            for (uint32_t i = 0; i < memoryRangeCount; ++i)
            {
                current_memory_wrapper = reinterpret_cast<const DeviceMemoryWrapper*>(pMemoryRanges[i].memory);

                if ((current_memory_wrapper != nullptr) && (current_memory_wrapper->mapped_data != nullptr))
                {
                    assert(pMemoryRanges[i].offset >= current_memory_wrapper->mapped_offset);

                    // The mapped pointer already includes the mapped offset.  Because the memory range
                    // offset is realtive to the start of the memory object, we need to adjust it to be
                    // realitve to the start of the mapped pointer.
                    VkDeviceSize relative_offset = pMemoryRanges[i].offset - current_memory_wrapper->mapped_offset;
                    VkDeviceSize size            = pMemoryRanges[i].size;
                    if (size == VK_WHOLE_SIZE)
                    {
                        size = current_memory_wrapper->allocation_size - pMemoryRanges[i].offset;
                    }

                    WriteFillMemoryCmd(
                        current_memory_wrapper->handle_id, relative_offset, size, current_memory_wrapper->mapped_data);
                }
            }
        }
    }
}

void TraceManager::PreProcess_vkUnmapMemory(VkDevice device, VkDeviceMemory memory)
{
    auto wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);
    assert(wrapper != nullptr);

    if (wrapper->mapped_data != nullptr)
    {
        if ((capture_mode_ & kModeTrack) == kModeTrack)
        {
            assert(state_tracker_ != nullptr);
            state_tracker_->TrackMappedMemory(device, memory, nullptr, 0, 0, 0);
        }
        else
        {
            // Perform subset of the state tracking performed by VulkanStateTracker::TrackMappedMemory, only storing
            // values needed for non-tracking capture.
            wrapper->mapped_data   = nullptr;
            wrapper->mapped_offset = 0;
            wrapper->mapped_size   = 0;
        }

        if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            manager->ProcessMemoryEntry(wrapper->handle_id,
                                        [this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
                                            WriteFillMemoryCmd(memory_id, offset, size, start_address);
                                        });

            manager->RemoveMemory(wrapper->handle_id);
        }
        else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
        {
            // Write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            VkDeviceSize size = wrapper->mapped_size;
            if (size == VK_WHOLE_SIZE)
            {
                size = wrapper->allocation_size;
            }

            WriteFillMemoryCmd(wrapper->handle_id, 0, size, wrapper->mapped_data);

            {
                std::lock_guard<std::mutex> lock(mapped_memory_lock_);
                mapped_memory_.erase(wrapper);
            }
        }
    }
    else
    {
        GFXRECON_LOG_WARNING(
            "Attempting to unmap VkDeviceMemory object with handle = %" PRIx64 " that has not been mapped", memory);
    }
}

void TraceManager::PreProcess_vkFreeMemory(VkDevice                     device,
                                           VkDeviceMemory               memory,
                                           const VkAllocationCallbacks* pAllocator)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if (memory != VK_NULL_HANDLE)
    {
        auto wrapper = reinterpret_cast<DeviceMemoryWrapper*>(memory);

        if ((memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard) &&
            (wrapper->mapped_data != nullptr))
        {
            util::PageGuardManager* manager = util::PageGuardManager::Get();
            assert(manager != nullptr);

            manager->RemoveMemory(wrapper->handle_id);

            if (page_guard_external_memory_)
            {
                size_t external_memory_size = manager->GetAlignedSize(static_cast<size_t>(wrapper->allocation_size));
                manager->FreeMemory(wrapper->external_allocation, external_memory_size);
            }
        }
    }
}

void TraceManager::PreProcess_vkQueueSubmit(VkQueue             queue,
                                            uint32_t            submitCount,
                                            const VkSubmitInfo* pSubmits,
                                            VkFence             fence)
{
    GFXRECON_UNREFERENCED_PARAMETER(queue);
    GFXRECON_UNREFERENCED_PARAMETER(submitCount);
    GFXRECON_UNREFERENCED_PARAMETER(pSubmits);
    GFXRECON_UNREFERENCED_PARAMETER(fence);

    if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kPageGuard)
    {
        util::PageGuardManager* manager = util::PageGuardManager::Get();
        assert(manager != nullptr);

        manager->ProcessMemoryEntries([this](uint64_t memory_id, void* start_address, size_t offset, size_t size) {
            WriteFillMemoryCmd(memory_id, offset, size, start_address);
        });
    }
    else if (memory_tracking_mode_ == CaptureSettings::MemoryTrackingMode::kUnassisted)
    {
        std::lock_guard<std::mutex> lock(mapped_memory_lock_);

        for (auto wrapper : mapped_memory_)
        {
            // If the memory is mapped, write the entire mapped region.
            // We set offset to 0, because the pointer returned by vkMapMemory already includes the offset.
            WriteFillMemoryCmd(wrapper->handle_id, 0, wrapper->mapped_size, wrapper->mapped_data);
        }
    }
}

void TraceManager::PreProcess_vkCreateDescriptorUpdateTemplate(VkResult                                    result,
                                                               VkDevice                                    device,
                                                               const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
                                                               const VkAllocationCallbacks*                pAllocator,
                                                               VkDescriptorUpdateTemplate* pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

void TraceManager::PreProcess_vkCreateDescriptorUpdateTemplateKHR(
    VkResult                                    result,
    VkDevice                                    device,
    const VkDescriptorUpdateTemplateCreateInfo* pCreateInfo,
    const VkAllocationCallbacks*                pAllocator,
    VkDescriptorUpdateTemplate*                 pDescriptorUpdateTemplate)
{
    GFXRECON_UNREFERENCED_PARAMETER(device);
    GFXRECON_UNREFERENCED_PARAMETER(pAllocator);

    if ((result == VK_SUCCESS) && (pCreateInfo != nullptr) && (pDescriptorUpdateTemplate != nullptr))
    {
        SetDescriptorUpdateTemplateInfo((*pDescriptorUpdateTemplate), pCreateInfo);
    }
}

#if defined(__ANDROID__)
void TraceManager::OverrideGetPhysicalDeviceSurfacePresentModesKHR(uint32_t*         pPresentModeCount,
                                                                   VkPresentModeKHR* pPresentModes)
{
    assert((pPresentModeCount != nullptr) && (pPresentModes != nullptr));

    for (uint32_t i = 0; i < (*pPresentModeCount); ++i)
    {
        pPresentModes[i] = VK_PRESENT_MODE_FIFO_KHR;
    }
}
#endif

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
