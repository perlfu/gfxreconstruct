/*
** Copyright (c) 2018-2021 Valve Corporation
** Copyright (c) 2018-2021 LunarG, Inc.
**
** Permission is hereby granted, free of charge, to any person obtaining a
** copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included in
** all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
*/

/*
** This file is generated from the Khronos Vulkan XML API Registry.
**
*/

#include "generated/generated_vulkan_struct_encoders.h"

#include "encode/parameter_encoder.h"
#include "encode/struct_pointer_encoder.h"
#include "encode/vulkan_capture_manager.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <cassert>
#include <cstdio>
#include <memory>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(encode)

void EncodePNextStruct(ParameterEncoder* encoder, const void* value)
{
    assert(encoder != nullptr);

    auto base = reinterpret_cast<const VkBaseInStructure*>(value);

    // Ignore the structures added to the pnext chain by the loader.
    while ((base != nullptr) && ((base->sType == VK_STRUCTURE_TYPE_LOADER_INSTANCE_CREATE_INFO) ||
                                 (base->sType == VK_STRUCTURE_TYPE_LOADER_DEVICE_CREATE_INFO)))
    {
        base = base->pNext;
    }

    if (base != nullptr)
    {
        switch (base->sType)
        {
        default:
            {
                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.
                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                VulkanCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                EncodePNextStruct(encoder, base->pNext);
            }
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice16BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedRequirements*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryDedicatedAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryAllocateFlagsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupRenderPassBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupCommandBufferBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupBindSparseInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindBufferMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemoryDeviceGroupInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupDeviceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFeatures2*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePointClippingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassInputAttachmentAspectCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineTessellationDomainOriginStateCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassMultiviewCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVariablePointersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProtectedMemoryProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkProtectedSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImagePlaneMemoryInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImagePlaneMemoryRequirementsInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerYcbcrConversionFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerYcbcrConversionImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalImageFormatInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalImageFormatProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIDProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryBufferCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance3Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDrawParametersFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan11Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan11Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan12Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkan12Properties*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageFormatListCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice8BitStorageFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDriverProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicInt64Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderFloat16Int8Features*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFloatControlsProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetLayoutBindingFlagsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDescriptorIndexingProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorSetVariableDescriptorCountLayoutSupport*>(base));
            break;
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSubpassDescriptionDepthStencilResolve*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthStencilResolveProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceScalarBlockLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageStencilUsageCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerReductionModeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSamplerFilterMinmaxProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVulkanMemoryModelFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImagelessFramebufferFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFramebufferAttachmentsCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassAttachmentBeginInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceUniformBufferStandardLayoutFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentReferenceStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentDescriptionStencilLayout*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceHostQueryResetFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTimelineSemaphoreProperties*>(base));
            break;
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSemaphoreTypeCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTimelineSemaphoreSubmitInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeatures*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferOpaqueCaptureAddressCreateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryOpaqueCaptureAddressAllocateInfo*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBindImageMemorySwapchainInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceGroupSwapchainCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayPresentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRenderingCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDynamicRenderingFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceRenderingInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentShadingRateAttachmentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderingFragmentDensityMapAttachmentInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAttachmentSampleCountInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMultiviewPerViewAttributesInfoNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryFdInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportSemaphoreWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkD3D12FenceSubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePushDescriptorPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentRegionsKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSharedPresentSurfaceCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportFenceWin32HandleInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePerformanceQueryPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPerformanceQuerySubmitInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePortabilitySubsetFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePortabilitySubsetPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderClockFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFragmentShadingRateAttachmentInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineFragmentShadingRateStateCreateInfoKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRatePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceProtectedCapabilitiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentWaitFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentIdKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePresentIdFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryBarrier2KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSynchronization2FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyCheckpointProperties2NV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFormatProperties3KHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance4FeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMaintenance4PropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugReportCallbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateRasterizationOrderAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationBufferCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDedicatedAllocationMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTransformFeedbackPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationStateStreamCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkTextureLODGatherFormatPropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCornerSampledImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalMemoryImageCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryAllocateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExportMemoryWin32HandleInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWin32KeyedMutexAcquireReleaseInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFlagsEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageViewASTCDecodeModeEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceASTCDecodeFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConditionalRenderingFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceConditionalRenderingInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportWScalingStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainCounterCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentTimesInfoGOOGLE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportSwizzleStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiscardRectanglePropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineDiscardRectangleStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceConservativeRasterizationPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationConservativeStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDepthClipEnableFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationDepthClipStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDebugUtilsMessengerCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferUsageANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatPropertiesANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportAndroidHardwareBufferInfoANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkExternalFormatANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAndroidHardwareBufferFormatProperties2ANDROID*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInlineUniformBlockPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetInlineUniformBlockEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDescriptorPoolInlineUniformBlockCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSampleLocationsInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassSampleLocationsBeginInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineSampleLocationsStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSampleLocationsPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorBlendAdvancedStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageToColorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageModulationStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderSMBuiltinsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDrmFormatModifierPropertiesListEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageDrmFormatModifierInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierListCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImageDrmFormatModifierExplicitCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDrmFormatModifierPropertiesList2EXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkShaderModuleValidationCacheCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportShadingRateImageStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImageFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShadingRateImagePropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportCoarseSampleOrderStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRepresentativeFragmentTestStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageViewImageFormatInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkFilterCubicImageViewImageFormatPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceQueueGlobalPriorityCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryHostPointerInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryHostPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCompilerControlCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCorePropertiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceMemoryOverallocationCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineVertexInputDivisorStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPresentFrameTokenGGP*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCreationFeedbackCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceComputeShaderDerivativesFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMeshShaderPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderImageFootprintFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineViewportExclusiveScissorStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExclusiveScissorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyCheckpointPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueryPoolPerformanceQueryCreateInfoINTEL*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePCIBusInfoPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDisplayNativeHdrSurfaceCapabilitiesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSwapchainDisplayNativeHdrCreateInfoAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMapPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassFragmentDensityMapCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceSubgroupSizeControlPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderCoreProperties2AMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoherentMemoryFeaturesAMD*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryBudgetPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMemoryPriorityFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMemoryPriorityAllocateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBufferDeviceAddressFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkBufferDeviceAddressCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkValidationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCooperativeMatrixPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCoverageReductionModeFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineCoverageReductionStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcrImageArraysFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProvokingVertexFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceProvokingVertexPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationProvokingVertexStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceCapabilitiesFullScreenExclusiveEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSurfaceFullScreenExclusiveWin32InfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceLineRasterizationPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineRasterizationLineStateCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloatFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceIndexTypeUint8FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkGraphicsPipelineShaderGroupsCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInheritedViewportScissorFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceViewportScissorInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkRenderPassTransformBeginInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCommandBufferInheritanceRenderPassTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDeviceMemoryReportFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDeviceMemoryReportCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRobustness2PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerCustomBorderColorCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceCustomBorderColorFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrivateDataFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDevicePrivateDataCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDiagnosticsConfigFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkDeviceDiagnosticsConfigCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineFragmentShadingRateEnumStateCreateInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureGeometryMotionTrianglesDataNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkAccelerationStructureMotionInfoNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingMotionBlurFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceFragmentDensityMap2PropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            EncodeStructPtr(encoder, reinterpret_cast<const VkCopyCommandTransformInfoQCOM*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceImageRobustnessFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevice4444FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE:
            EncodeStructPtr(encoder, reinterpret_cast<const VkMutableDescriptorTypeCreateInfoVALVE*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceDrmPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            EncodeStructPtr(encoder, reinterpret_cast<const VkImportMemoryZirconHandleInfoFUCHSIA*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceInvocationMaskFeaturesHUAWEI*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExternalMemoryRDMAFeaturesNV*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceExtendedDynamicState2FeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceColorWriteEnableFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPipelineColorWriteCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkQueueFamilyGlobalPriorityPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiDrawFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceMultiDrawPropertiesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceBorderColorSwizzleFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkSamplerBorderColorComponentMappingCreateInfoEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT*>(base));
            break;
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkWriteDescriptorSetAccelerationStructureKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAccelerationStructureFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceAccelerationStructurePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPipelineFeaturesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayTracingPipelinePropertiesKHR*>(base));
            break;
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            EncodeStructPtr(encoder, reinterpret_cast<const VkPhysicalDeviceRayQueryFeaturesKHR*>(base));
            break;
        }
    }
    else
    {
        // pNext was either NULL or an ignored loader specific struct.  Write an encoding for a NULL pointer.
        encoder->EncodeStructPtrPreamble(nullptr);
    }
}

std::vector<std::vector<uint8_t>> CopyPNextStructs(const void* value)
{
    std::vector<std::vector<uint8_t>> ret;
    std::vector<uint8_t> pnext;
    auto base = reinterpret_cast<const VkBaseInStructure*>(value);
    while(base)
    {
        switch (base->sType)
        {
            default:
            {
                // pNext is unrecognized.  Write warning message to indicate it will be omitted from the capture and check to see if it points to a recognized value.
                int32_t message_size = std::snprintf(nullptr, 0, "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                std::unique_ptr<char[]> message = std::make_unique<char[]>(message_size + 1); // Add 1 for null-terminator.
                std::snprintf(message.get(), (message_size + 1), "A pNext value with unrecognized VkStructureType = %d was omitted from the capture file, which may cause replay to fail.", base->sType);
                VulkanCaptureManager::Get()->WriteDisplayMessageCmd(message.get());
                GFXRECON_LOG_WARNING("%s", message.get());
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSubgroupProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSubgroupProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_16BIT_STORAGE_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDevice16BitStorageFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevice16BitStorageFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_REQUIREMENTS:
            {
                pnext.resize(sizeof(VkMemoryDedicatedRequirements));
                std::memcpy(pnext.data(), base, sizeof(VkMemoryDedicatedRequirements));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MEMORY_DEDICATED_ALLOCATE_INFO:
            {
                pnext.resize(sizeof(VkMemoryDedicatedAllocateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkMemoryDedicatedAllocateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MEMORY_ALLOCATE_FLAGS_INFO:
            {
                pnext.resize(sizeof(VkMemoryAllocateFlagsInfo));
                std::memcpy(pnext.data(), base, sizeof(VkMemoryAllocateFlagsInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_RENDER_PASS_BEGIN_INFO:
            {
                pnext.resize(sizeof(VkDeviceGroupRenderPassBeginInfo));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceGroupRenderPassBeginInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_COMMAND_BUFFER_BEGIN_INFO:
            {
                pnext.resize(sizeof(VkDeviceGroupCommandBufferBeginInfo));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceGroupCommandBufferBeginInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SUBMIT_INFO:
            {
                pnext.resize(sizeof(VkDeviceGroupSubmitInfo));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceGroupSubmitInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_BIND_SPARSE_INFO:
            {
                pnext.resize(sizeof(VkDeviceGroupBindSparseInfo));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceGroupBindSparseInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_BIND_BUFFER_MEMORY_DEVICE_GROUP_INFO:
            {
                pnext.resize(sizeof(VkBindBufferMemoryDeviceGroupInfo));
                std::memcpy(pnext.data(), base, sizeof(VkBindBufferMemoryDeviceGroupInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_DEVICE_GROUP_INFO:
            {
                pnext.resize(sizeof(VkBindImageMemoryDeviceGroupInfo));
                std::memcpy(pnext.data(), base, sizeof(VkBindImageMemoryDeviceGroupInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_DEVICE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkDeviceGroupDeviceCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceGroupDeviceCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FEATURES_2:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFeatures2));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFeatures2));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_POINT_CLIPPING_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDevicePointClippingProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePointClippingProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDER_PASS_INPUT_ATTACHMENT_ASPECT_CREATE_INFO:
            {
                pnext.resize(sizeof(VkRenderPassInputAttachmentAspectCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkRenderPassInputAttachmentAspectCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_USAGE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkImageViewUsageCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkImageViewUsageCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_TESSELLATION_DOMAIN_ORIGIN_STATE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkPipelineTessellationDomainOriginStateCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineTessellationDomainOriginStateCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDER_PASS_MULTIVIEW_CREATE_INFO:
            {
                pnext.resize(sizeof(VkRenderPassMultiviewCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkRenderPassMultiviewCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMultiviewFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMultiviewFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMultiviewProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMultiviewProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VARIABLE_POINTERS_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVariablePointersFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVariablePointersFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceProtectedMemoryFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROTECTED_MEMORY_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceProtectedMemoryProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceProtectedMemoryProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PROTECTED_SUBMIT_INFO:
            {
                pnext.resize(sizeof(VkProtectedSubmitInfo));
                std::memcpy(pnext.data(), base, sizeof(VkProtectedSubmitInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_INFO:
            {
                pnext.resize(sizeof(VkSamplerYcbcrConversionInfo));
                std::memcpy(pnext.data(), base, sizeof(VkSamplerYcbcrConversionInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_BIND_IMAGE_PLANE_MEMORY_INFO:
            {
                pnext.resize(sizeof(VkBindImagePlaneMemoryInfo));
                std::memcpy(pnext.data(), base, sizeof(VkBindImagePlaneMemoryInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_PLANE_MEMORY_REQUIREMENTS_INFO:
            {
                pnext.resize(sizeof(VkImagePlaneMemoryRequirementsInfo));
                std::memcpy(pnext.data(), base, sizeof(VkImagePlaneMemoryRequirementsInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_YCBCR_CONVERSION_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSamplerYcbcrConversionFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SAMPLER_YCBCR_CONVERSION_IMAGE_FORMAT_PROPERTIES:
            {
                pnext.resize(sizeof(VkSamplerYcbcrConversionImageFormatProperties));
                std::memcpy(pnext.data(), base, sizeof(VkSamplerYcbcrConversionImageFormatProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_IMAGE_FORMAT_INFO:
            {
                pnext.resize(sizeof(VkPhysicalDeviceExternalImageFormatInfo));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceExternalImageFormatInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXTERNAL_IMAGE_FORMAT_PROPERTIES:
            {
                pnext.resize(sizeof(VkExternalImageFormatProperties));
                std::memcpy(pnext.data(), base, sizeof(VkExternalImageFormatProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ID_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceIDProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceIDProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkExternalMemoryImageCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkExternalMemoryImageCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_BUFFER_CREATE_INFO:
            {
                pnext.resize(sizeof(VkExternalMemoryBufferCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkExternalMemoryBufferCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO:
            {
                pnext.resize(sizeof(VkExportMemoryAllocateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkExportMemoryAllocateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkExportFenceCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkExportFenceCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkExportSemaphoreCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkExportSemaphoreCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_3_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMaintenance3Properties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMaintenance3Properties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DRAW_PARAMETERS_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderDrawParametersFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVulkan11Features));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVulkan11Features));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_1_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVulkan11Properties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVulkan11Properties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVulkan12Features));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVulkan12Features));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_1_2_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVulkan12Properties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVulkan12Properties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_FORMAT_LIST_CREATE_INFO:
            {
                pnext.resize(sizeof(VkImageFormatListCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkImageFormatListCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_8BIT_STORAGE_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDevice8BitStorageFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevice8BitStorageFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRIVER_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDriverProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDriverProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_INT64_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderAtomicInt64Features));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_FLOAT16_INT8_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderFloat16Int8Features));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FLOAT_CONTROLS_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFloatControlsProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFloatControlsProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_BINDING_FLAGS_CREATE_INFO:
            {
                pnext.resize(sizeof(VkDescriptorSetLayoutBindingFlagsCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkDescriptorSetLayoutBindingFlagsCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDescriptorIndexingFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DESCRIPTOR_INDEXING_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDescriptorIndexingProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDescriptorIndexingProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_ALLOCATE_INFO:
            {
                pnext.resize(sizeof(VkDescriptorSetVariableDescriptorCountAllocateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkDescriptorSetVariableDescriptorCountAllocateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DESCRIPTOR_SET_VARIABLE_DESCRIPTOR_COUNT_LAYOUT_SUPPORT:
            {
                pnext.resize(sizeof(VkDescriptorSetVariableDescriptorCountLayoutSupport));
                std::memcpy(pnext.data(), base, sizeof(VkDescriptorSetVariableDescriptorCountLayoutSupport));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SUBPASS_DESCRIPTION_DEPTH_STENCIL_RESOLVE:
            {
                pnext.resize(sizeof(VkSubpassDescriptionDepthStencilResolve));
                std::memcpy(pnext.data(), base, sizeof(VkSubpassDescriptionDepthStencilResolve));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_STENCIL_RESOLVE_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDepthStencilResolveProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDepthStencilResolveProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SCALAR_BLOCK_LAYOUT_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceScalarBlockLayoutFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_STENCIL_USAGE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkImageStencilUsageCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkImageStencilUsageCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SAMPLER_REDUCTION_MODE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkSamplerReductionModeCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkSamplerReductionModeCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLER_FILTER_MINMAX_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSamplerFilterMinmaxProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSamplerFilterMinmaxProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VULKAN_MEMORY_MODEL_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVulkanMemoryModelFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGELESS_FRAMEBUFFER_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceImagelessFramebufferFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_FRAMEBUFFER_ATTACHMENTS_CREATE_INFO:
            {
                pnext.resize(sizeof(VkFramebufferAttachmentsCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkFramebufferAttachmentsCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDER_PASS_ATTACHMENT_BEGIN_INFO:
            {
                pnext.resize(sizeof(VkRenderPassAttachmentBeginInfo));
                std::memcpy(pnext.data(), base, sizeof(VkRenderPassAttachmentBeginInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_UNIFORM_BUFFER_STANDARD_LAYOUT_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceUniformBufferStandardLayoutFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_EXTENDED_TYPES_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderSubgroupExtendedTypesFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SEPARATE_DEPTH_STENCIL_LAYOUTS_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSeparateDepthStencilLayoutsFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ATTACHMENT_REFERENCE_STENCIL_LAYOUT:
            {
                pnext.resize(sizeof(VkAttachmentReferenceStencilLayout));
                std::memcpy(pnext.data(), base, sizeof(VkAttachmentReferenceStencilLayout));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ATTACHMENT_DESCRIPTION_STENCIL_LAYOUT:
            {
                pnext.resize(sizeof(VkAttachmentDescriptionStencilLayout));
                std::memcpy(pnext.data(), base, sizeof(VkAttachmentDescriptionStencilLayout));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_HOST_QUERY_RESET_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceHostQueryResetFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceHostQueryResetFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceTimelineSemaphoreFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TIMELINE_SEMAPHORE_PROPERTIES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceTimelineSemaphoreProperties));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceTimelineSemaphoreProperties));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SEMAPHORE_TYPE_CREATE_INFO:
            {
                pnext.resize(sizeof(VkSemaphoreTypeCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkSemaphoreTypeCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_TIMELINE_SEMAPHORE_SUBMIT_INFO:
            {
                pnext.resize(sizeof(VkTimelineSemaphoreSubmitInfo));
                std::memcpy(pnext.data(), base, sizeof(VkTimelineSemaphoreSubmitInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES:
            {
                pnext.resize(sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceBufferDeviceAddressFeatures));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_BUFFER_OPAQUE_CAPTURE_ADDRESS_CREATE_INFO:
            {
                pnext.resize(sizeof(VkBufferOpaqueCaptureAddressCreateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkBufferOpaqueCaptureAddressCreateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MEMORY_OPAQUE_CAPTURE_ADDRESS_ALLOCATE_INFO:
            {
                pnext.resize(sizeof(VkMemoryOpaqueCaptureAddressAllocateInfo));
                std::memcpy(pnext.data(), base, sizeof(VkMemoryOpaqueCaptureAddressAllocateInfo));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_SWAPCHAIN_CREATE_INFO_KHR:
            {
                pnext.resize(sizeof(VkImageSwapchainCreateInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkImageSwapchainCreateInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_BIND_IMAGE_MEMORY_SWAPCHAIN_INFO_KHR:
            {
                pnext.resize(sizeof(VkBindImageMemorySwapchainInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkBindImageMemorySwapchainInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_PRESENT_INFO_KHR:
            {
                pnext.resize(sizeof(VkDeviceGroupPresentInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceGroupPresentInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_GROUP_SWAPCHAIN_CREATE_INFO_KHR:
            {
                pnext.resize(sizeof(VkDeviceGroupSwapchainCreateInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceGroupSwapchainCreateInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DISPLAY_PRESENT_INFO_KHR:
            {
                pnext.resize(sizeof(VkDisplayPresentInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkDisplayPresentInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_RENDERING_CREATE_INFO_KHR:
            {
                pnext.resize(sizeof(VkPipelineRenderingCreateInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRenderingCreateInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DYNAMIC_RENDERING_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDynamicRenderingFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDynamicRenderingFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDERING_INFO_KHR:
            {
                pnext.resize(sizeof(VkCommandBufferInheritanceRenderingInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkCommandBufferInheritanceRenderingInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
                pnext.resize(sizeof(VkRenderingFragmentShadingRateAttachmentInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkRenderingFragmentShadingRateAttachmentInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDERING_FRAGMENT_DENSITY_MAP_ATTACHMENT_INFO_EXT:
            {
                pnext.resize(sizeof(VkRenderingFragmentDensityMapAttachmentInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkRenderingFragmentDensityMapAttachmentInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ATTACHMENT_SAMPLE_COUNT_INFO_AMD:
            {
                pnext.resize(sizeof(VkAttachmentSampleCountInfoAMD));
                std::memcpy(pnext.data(), base, sizeof(VkAttachmentSampleCountInfoAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MULTIVIEW_PER_VIEW_ATTRIBUTES_INFO_NVX:
            {
                pnext.resize(sizeof(VkMultiviewPerViewAttributesInfoNVX));
                std::memcpy(pnext.data(), base, sizeof(VkMultiviewPerViewAttributesInfoNVX));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
                pnext.resize(sizeof(VkImportMemoryWin32HandleInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkImportMemoryWin32HandleInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_KHR:
            {
                pnext.resize(sizeof(VkExportMemoryWin32HandleInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkExportMemoryWin32HandleInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_FD_INFO_KHR:
            {
                pnext.resize(sizeof(VkImportMemoryFdInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkImportMemoryFdInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_KHR:
            {
                pnext.resize(sizeof(VkWin32KeyedMutexAcquireReleaseInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkWin32KeyedMutexAcquireReleaseInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_SEMAPHORE_WIN32_HANDLE_INFO_KHR:
            {
                pnext.resize(sizeof(VkExportSemaphoreWin32HandleInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkExportSemaphoreWin32HandleInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_D3D12_FENCE_SUBMIT_INFO_KHR:
            {
                pnext.resize(sizeof(VkD3D12FenceSubmitInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkD3D12FenceSubmitInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PUSH_DESCRIPTOR_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePushDescriptorPropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePushDescriptorPropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PRESENT_REGIONS_KHR:
            {
                pnext.resize(sizeof(VkPresentRegionsKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPresentRegionsKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SHARED_PRESENT_SURFACE_CAPABILITIES_KHR:
            {
                pnext.resize(sizeof(VkSharedPresentSurfaceCapabilitiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkSharedPresentSurfaceCapabilitiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_FENCE_WIN32_HANDLE_INFO_KHR:
            {
                pnext.resize(sizeof(VkExportFenceWin32HandleInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkExportFenceWin32HandleInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePerformanceQueryFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePerformanceQueryFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PERFORMANCE_QUERY_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePerformanceQueryPropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePerformanceQueryPropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_CREATE_INFO_KHR:
            {
                pnext.resize(sizeof(VkQueryPoolPerformanceCreateInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkQueryPoolPerformanceCreateInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PERFORMANCE_QUERY_SUBMIT_INFO_KHR:
            {
                pnext.resize(sizeof(VkPerformanceQuerySubmitInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPerformanceQuerySubmitInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePortabilitySubsetFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePortabilitySubsetFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PORTABILITY_SUBSET_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePortabilitySubsetPropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePortabilitySubsetPropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CLOCK_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderClockFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderClockFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_TERMINATE_INVOCATION_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderTerminateInvocationFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_FRAGMENT_SHADING_RATE_ATTACHMENT_INFO_KHR:
            {
                pnext.resize(sizeof(VkFragmentShadingRateAttachmentInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkFragmentShadingRateAttachmentInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_STATE_CREATE_INFO_KHR:
            {
                pnext.resize(sizeof(VkPipelineFragmentShadingRateStateCreateInfoKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineFragmentShadingRateStateCreateInfoKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentShadingRateFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentShadingRateFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentShadingRatePropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentShadingRatePropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SURFACE_PROTECTED_CAPABILITIES_KHR:
            {
                pnext.resize(sizeof(VkSurfaceProtectedCapabilitiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkSurfaceProtectedCapabilitiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_WAIT_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePresentWaitFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePresentWaitFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_EXECUTABLE_PROPERTIES_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePipelineExecutablePropertiesFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderIntegerDotProductFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_DOT_PRODUCT_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderIntegerDotProductPropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PRESENT_ID_KHR:
            {
                pnext.resize(sizeof(VkPresentIdKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPresentIdKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRESENT_ID_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDevicePresentIdFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePresentIdFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MEMORY_BARRIER_2_KHR:
            {
                pnext.resize(sizeof(VkMemoryBarrier2KHR));
                std::memcpy(pnext.data(), base, sizeof(VkMemoryBarrier2KHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SYNCHRONIZATION_2_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSynchronization2FeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSynchronization2FeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_2_NV:
            {
                pnext.resize(sizeof(VkQueueFamilyCheckpointProperties2NV));
                std::memcpy(pnext.data(), base, sizeof(VkQueueFamilyCheckpointProperties2NV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SUBGROUP_UNIFORM_CONTROL_FLOW_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderSubgroupUniformControlFlowFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ZERO_INITIALIZE_WORKGROUP_MEMORY_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceZeroInitializeWorkgroupMemoryFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_WORKGROUP_MEMORY_EXPLICIT_LAYOUT_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceWorkgroupMemoryExplicitLayoutFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_FORMAT_PROPERTIES_3_KHR:
            {
                pnext.resize(sizeof(VkFormatProperties3KHR));
                std::memcpy(pnext.data(), base, sizeof(VkFormatProperties3KHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMaintenance4FeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMaintenance4FeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MAINTENANCE_4_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMaintenance4PropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMaintenance4PropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEBUG_REPORT_CALLBACK_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkDebugReportCallbackCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkDebugReportCallbackCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_RASTERIZATION_ORDER_AMD:
            {
                pnext.resize(sizeof(VkPipelineRasterizationStateRasterizationOrderAMD));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRasterizationStateRasterizationOrderAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_IMAGE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkDedicatedAllocationImageCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkDedicatedAllocationImageCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_BUFFER_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkDedicatedAllocationBufferCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkDedicatedAllocationBufferCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEDICATED_ALLOCATION_MEMORY_ALLOCATE_INFO_NV:
            {
                pnext.resize(sizeof(VkDedicatedAllocationMemoryAllocateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkDedicatedAllocationMemoryAllocateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceTransformFeedbackFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TRANSFORM_FEEDBACK_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceTransformFeedbackPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_STREAM_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineRasterizationStateStreamCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRasterizationStateStreamCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_TEXTURE_LOD_GATHER_FORMAT_PROPERTIES_AMD:
            {
                pnext.resize(sizeof(VkTextureLODGatherFormatPropertiesAMD));
                std::memcpy(pnext.data(), base, sizeof(VkTextureLODGatherFormatPropertiesAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CORNER_SAMPLED_IMAGE_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceCornerSampledImageFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceCornerSampledImageFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXTERNAL_MEMORY_IMAGE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkExternalMemoryImageCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkExternalMemoryImageCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_ALLOCATE_INFO_NV:
            {
                pnext.resize(sizeof(VkExportMemoryAllocateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkExportMemoryAllocateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
                pnext.resize(sizeof(VkImportMemoryWin32HandleInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkImportMemoryWin32HandleInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXPORT_MEMORY_WIN32_HANDLE_INFO_NV:
            {
                pnext.resize(sizeof(VkExportMemoryWin32HandleInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkExportMemoryWin32HandleInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_WIN32_KEYED_MUTEX_ACQUIRE_RELEASE_INFO_NV:
            {
                pnext.resize(sizeof(VkWin32KeyedMutexAcquireReleaseInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkWin32KeyedMutexAcquireReleaseInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_VALIDATION_FLAGS_EXT:
            {
                pnext.resize(sizeof(VkValidationFlagsEXT));
                std::memcpy(pnext.data(), base, sizeof(VkValidationFlagsEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXTURE_COMPRESSION_ASTC_HDR_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceTextureCompressionASTCHDRFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_VIEW_ASTC_DECODE_MODE_EXT:
            {
                pnext.resize(sizeof(VkImageViewASTCDecodeModeEXT));
                std::memcpy(pnext.data(), base, sizeof(VkImageViewASTCDecodeModeEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ASTC_DECODE_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceASTCDecodeFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceASTCDecodeFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONDITIONAL_RENDERING_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceConditionalRenderingFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceConditionalRenderingFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_CONDITIONAL_RENDERING_INFO_EXT:
            {
                pnext.resize(sizeof(VkCommandBufferInheritanceConditionalRenderingInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkCommandBufferInheritanceConditionalRenderingInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_W_SCALING_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineViewportWScalingStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineViewportWScalingStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SWAPCHAIN_COUNTER_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkSwapchainCounterCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkSwapchainCounterCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PRESENT_TIMES_INFO_GOOGLE:
            {
                pnext.resize(sizeof(VkPresentTimesInfoGOOGLE));
                std::memcpy(pnext.data(), base, sizeof(VkPresentTimesInfoGOOGLE));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTIVIEW_PER_VIEW_ATTRIBUTES_PROPERTIES_NVX:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMultiviewPerViewAttributesPropertiesNVX));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SWIZZLE_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineViewportSwizzleStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineViewportSwizzleStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DISCARD_RECTANGLE_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDiscardRectanglePropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDiscardRectanglePropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_DISCARD_RECTANGLE_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineDiscardRectangleStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineDiscardRectangleStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CONSERVATIVE_RASTERIZATION_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceConservativeRasterizationPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceConservativeRasterizationPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_CONSERVATIVE_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineRasterizationConservativeStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRasterizationConservativeStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEPTH_CLIP_ENABLE_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDepthClipEnableFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDepthClipEnableFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_DEPTH_CLIP_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineRasterizationDepthClipStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRasterizationDepthClipStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkDebugUtilsMessengerCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkDebugUtilsMessengerCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_USAGE_ANDROID:
            {
                pnext.resize(sizeof(VkAndroidHardwareBufferUsageANDROID));
                std::memcpy(pnext.data(), base, sizeof(VkAndroidHardwareBufferUsageANDROID));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_ANDROID:
            {
                pnext.resize(sizeof(VkAndroidHardwareBufferFormatPropertiesANDROID));
                std::memcpy(pnext.data(), base, sizeof(VkAndroidHardwareBufferFormatPropertiesANDROID));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMPORT_ANDROID_HARDWARE_BUFFER_INFO_ANDROID:
            {
                pnext.resize(sizeof(VkImportAndroidHardwareBufferInfoANDROID));
                std::memcpy(pnext.data(), base, sizeof(VkImportAndroidHardwareBufferInfoANDROID));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_EXTERNAL_FORMAT_ANDROID:
            {
                pnext.resize(sizeof(VkExternalFormatANDROID));
                std::memcpy(pnext.data(), base, sizeof(VkExternalFormatANDROID));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ANDROID_HARDWARE_BUFFER_FORMAT_PROPERTIES_2_ANDROID:
            {
                pnext.resize(sizeof(VkAndroidHardwareBufferFormatProperties2ANDROID));
                std::memcpy(pnext.data(), base, sizeof(VkAndroidHardwareBufferFormatProperties2ANDROID));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceInlineUniformBlockFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceInlineUniformBlockFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INLINE_UNIFORM_BLOCK_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceInlineUniformBlockPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceInlineUniformBlockPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_INLINE_UNIFORM_BLOCK_EXT:
            {
                pnext.resize(sizeof(VkWriteDescriptorSetInlineUniformBlockEXT));
                std::memcpy(pnext.data(), base, sizeof(VkWriteDescriptorSetInlineUniformBlockEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_INLINE_UNIFORM_BLOCK_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkDescriptorPoolInlineUniformBlockCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkDescriptorPoolInlineUniformBlockCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SAMPLE_LOCATIONS_INFO_EXT:
            {
                pnext.resize(sizeof(VkSampleLocationsInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkSampleLocationsInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDER_PASS_SAMPLE_LOCATIONS_BEGIN_INFO_EXT:
            {
                pnext.resize(sizeof(VkRenderPassSampleLocationsBeginInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkRenderPassSampleLocationsBeginInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_SAMPLE_LOCATIONS_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineSampleLocationsStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineSampleLocationsStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SAMPLE_LOCATIONS_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSampleLocationsPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSampleLocationsPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceBlendOperationAdvancedFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BLEND_OPERATION_ADVANCED_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceBlendOperationAdvancedPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_ADVANCED_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineColorBlendAdvancedStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineColorBlendAdvancedStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_TO_COLOR_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineCoverageToColorStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineCoverageToColorStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_MODULATION_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineCoverageModulationStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineCoverageModulationStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderSMBuiltinsPropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_SM_BUILTINS_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderSMBuiltinsFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_EXT:
            {
                pnext.resize(sizeof(VkDrmFormatModifierPropertiesListEXT));
                std::memcpy(pnext.data(), base, sizeof(VkDrmFormatModifierPropertiesListEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_DRM_FORMAT_MODIFIER_INFO_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceImageDrmFormatModifierInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceImageDrmFormatModifierInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_LIST_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkImageDrmFormatModifierListCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkImageDrmFormatModifierListCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMAGE_DRM_FORMAT_MODIFIER_EXPLICIT_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkImageDrmFormatModifierExplicitCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkImageDrmFormatModifierExplicitCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DRM_FORMAT_MODIFIER_PROPERTIES_LIST_2_EXT:
            {
                pnext.resize(sizeof(VkDrmFormatModifierPropertiesList2EXT));
                std::memcpy(pnext.data(), base, sizeof(VkDrmFormatModifierPropertiesList2EXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SHADER_MODULE_VALIDATION_CACHE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkShaderModuleValidationCacheCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkShaderModuleValidationCacheCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_SHADING_RATE_IMAGE_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineViewportShadingRateImageStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineViewportShadingRateImageStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShadingRateImageFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShadingRateImageFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADING_RATE_IMAGE_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShadingRateImagePropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShadingRateImagePropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_COARSE_SAMPLE_ORDER_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineViewportCoarseSampleOrderStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_NV:
            {
                pnext.resize(sizeof(VkWriteDescriptorSetAccelerationStructureNV));
                std::memcpy(pnext.data(), base, sizeof(VkWriteDescriptorSetAccelerationStructureNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRayTracingPropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRayTracingPropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_REPRESENTATIVE_FRAGMENT_TEST_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRepresentativeFragmentTestFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_REPRESENTATIVE_FRAGMENT_TEST_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineRepresentativeFragmentTestStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRepresentativeFragmentTestStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_VIEW_IMAGE_FORMAT_INFO_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceImageViewImageFormatInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceImageViewImageFormatInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_FILTER_CUBIC_IMAGE_VIEW_IMAGE_FORMAT_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkFilterCubicImageViewImageFormatPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkFilterCubicImageViewImageFormatPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_QUEUE_GLOBAL_PRIORITY_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkDeviceQueueGlobalPriorityCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceQueueGlobalPriorityCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_HOST_POINTER_INFO_EXT:
            {
                pnext.resize(sizeof(VkImportMemoryHostPointerInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkImportMemoryHostPointerInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_HOST_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceExternalMemoryHostPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceExternalMemoryHostPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_COMPILER_CONTROL_CREATE_INFO_AMD:
            {
                pnext.resize(sizeof(VkPipelineCompilerControlCreateInfoAMD));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineCompilerControlCreateInfoAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_AMD:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderCorePropertiesAMD));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderCorePropertiesAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_MEMORY_OVERALLOCATION_CREATE_INFO_AMD:
            {
                pnext.resize(sizeof(VkDeviceMemoryOverallocationCreateInfoAMD));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceMemoryOverallocationCreateInfoAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVertexAttributeDivisorPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_DIVISOR_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineVertexInputDivisorStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineVertexInputDivisorStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_ATTRIBUTE_DIVISOR_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVertexAttributeDivisorFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PRESENT_FRAME_TOKEN_GGP:
            {
                pnext.resize(sizeof(VkPresentFrameTokenGGP));
                std::memcpy(pnext.data(), base, sizeof(VkPresentFrameTokenGGP));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_CREATION_FEEDBACK_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineCreationFeedbackCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineCreationFeedbackCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COMPUTE_SHADER_DERIVATIVES_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceComputeShaderDerivativesFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceComputeShaderDerivativesFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMeshShaderFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMeshShaderFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MESH_SHADER_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMeshShaderPropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMeshShaderPropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_BARYCENTRIC_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentShaderBarycentricFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_FOOTPRINT_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderImageFootprintFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderImageFootprintFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_EXCLUSIVE_SCISSOR_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineViewportExclusiveScissorStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineViewportExclusiveScissorStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXCLUSIVE_SCISSOR_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceExclusiveScissorFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceExclusiveScissorFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_CHECKPOINT_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkQueueFamilyCheckpointPropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkQueueFamilyCheckpointPropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_INTEGER_FUNCTIONS_2_FEATURES_INTEL:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderIntegerFunctions2FeaturesINTEL));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_QUERY_POOL_PERFORMANCE_QUERY_CREATE_INFO_INTEL:
            {
                pnext.resize(sizeof(VkQueryPoolPerformanceQueryCreateInfoINTEL));
                std::memcpy(pnext.data(), base, sizeof(VkQueryPoolPerformanceQueryCreateInfoINTEL));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PCI_BUS_INFO_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDevicePCIBusInfoPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePCIBusInfoPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DISPLAY_NATIVE_HDR_SURFACE_CAPABILITIES_AMD:
            {
                pnext.resize(sizeof(VkDisplayNativeHdrSurfaceCapabilitiesAMD));
                std::memcpy(pnext.data(), base, sizeof(VkDisplayNativeHdrSurfaceCapabilitiesAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SWAPCHAIN_DISPLAY_NATIVE_HDR_CREATE_INFO_AMD:
            {
                pnext.resize(sizeof(VkSwapchainDisplayNativeHdrCreateInfoAMD));
                std::memcpy(pnext.data(), base, sizeof(VkSwapchainDisplayNativeHdrCreateInfoAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentDensityMapFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentDensityMapFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentDensityMapPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentDensityMapPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDER_PASS_FRAGMENT_DENSITY_MAP_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkRenderPassFragmentDensityMapCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkRenderPassFragmentDensityMapCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSubgroupSizeControlFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSubgroupSizeControlFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SUBGROUP_SIZE_CONTROL_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceSubgroupSizeControlPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceSubgroupSizeControlPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_REQUIRED_SUBGROUP_SIZE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineShaderStageRequiredSubgroupSizeCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_CORE_PROPERTIES_2_AMD:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderCoreProperties2AMD));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderCoreProperties2AMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COHERENT_MEMORY_FEATURES_AMD:
            {
                pnext.resize(sizeof(VkPhysicalDeviceCoherentMemoryFeaturesAMD));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceCoherentMemoryFeaturesAMD));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_IMAGE_ATOMIC_INT64_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderImageAtomicInt64FeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_BUDGET_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMemoryBudgetPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMemoryBudgetPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MEMORY_PRIORITY_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMemoryPriorityFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMemoryPriorityFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MEMORY_PRIORITY_ALLOCATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkMemoryPriorityAllocateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkMemoryPriorityAllocateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEDICATED_ALLOCATION_IMAGE_ALIASING_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDedicatedAllocationImageAliasingFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BUFFER_DEVICE_ADDRESS_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceBufferDeviceAddressFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_BUFFER_DEVICE_ADDRESS_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkBufferDeviceAddressCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkBufferDeviceAddressCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_VALIDATION_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkValidationFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkValidationFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceCooperativeMatrixFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceCooperativeMatrixFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COOPERATIVE_MATRIX_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceCooperativeMatrixPropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceCooperativeMatrixPropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COVERAGE_REDUCTION_MODE_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceCoverageReductionModeFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceCoverageReductionModeFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_COVERAGE_REDUCTION_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineCoverageReductionStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineCoverageReductionStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADER_INTERLOCK_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentShaderInterlockFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_IMAGE_ARRAYS_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceYcbcrImageArraysFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceProvokingVertexFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceProvokingVertexFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PROVOKING_VERTEX_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceProvokingVertexPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceProvokingVertexPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_PROVOKING_VERTEX_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRasterizationProvokingVertexStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_INFO_EXT:
            {
                pnext.resize(sizeof(VkSurfaceFullScreenExclusiveInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkSurfaceFullScreenExclusiveInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SURFACE_CAPABILITIES_FULL_SCREEN_EXCLUSIVE_EXT:
            {
                pnext.resize(sizeof(VkSurfaceCapabilitiesFullScreenExclusiveEXT));
                std::memcpy(pnext.data(), base, sizeof(VkSurfaceCapabilitiesFullScreenExclusiveEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SURFACE_FULL_SCREEN_EXCLUSIVE_WIN32_INFO_EXT:
            {
                pnext.resize(sizeof(VkSurfaceFullScreenExclusiveWin32InfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkSurfaceFullScreenExclusiveWin32InfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceLineRasterizationFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceLineRasterizationFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_LINE_RASTERIZATION_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceLineRasterizationPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceLineRasterizationPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_LINE_STATE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineRasterizationLineStateCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineRasterizationLineStateCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderAtomicFloatFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INDEX_TYPE_UINT8_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceIndexTypeUint8FeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceIndexTypeUint8FeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceExtendedDynamicStateFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_ATOMIC_FLOAT_2_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderAtomicFloat2FeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_SHADER_DEMOTE_TO_HELPER_INVOCATION_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceShaderDemoteToHelperInvocationFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDeviceGeneratedCommandsPropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_GENERATED_COMMANDS_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDeviceGeneratedCommandsFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_SHADER_GROUPS_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkGraphicsPipelineShaderGroupsCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkGraphicsPipelineShaderGroupsCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INHERITED_VIEWPORT_SCISSOR_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceInheritedViewportScissorFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceInheritedViewportScissorFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_VIEWPORT_SCISSOR_INFO_NV:
            {
                pnext.resize(sizeof(VkCommandBufferInheritanceViewportScissorInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkCommandBufferInheritanceViewportScissorInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceTexelBufferAlignmentFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_TEXEL_BUFFER_ALIGNMENT_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceTexelBufferAlignmentPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_RENDER_PASS_TRANSFORM_BEGIN_INFO_QCOM:
            {
                pnext.resize(sizeof(VkRenderPassTransformBeginInfoQCOM));
                std::memcpy(pnext.data(), base, sizeof(VkRenderPassTransformBeginInfoQCOM));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_COMMAND_BUFFER_INHERITANCE_RENDER_PASS_TRANSFORM_INFO_QCOM:
            {
                pnext.resize(sizeof(VkCommandBufferInheritanceRenderPassTransformInfoQCOM));
                std::memcpy(pnext.data(), base, sizeof(VkCommandBufferInheritanceRenderPassTransformInfoQCOM));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DEVICE_MEMORY_REPORT_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDeviceMemoryReportFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_DEVICE_MEMORY_REPORT_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkDeviceDeviceMemoryReportCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceDeviceMemoryReportCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRobustness2FeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRobustness2FeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ROBUSTNESS_2_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRobustness2PropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRobustness2PropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SAMPLER_CUSTOM_BORDER_COLOR_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkSamplerCustomBorderColorCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkSamplerCustomBorderColorCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceCustomBorderColorPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceCustomBorderColorPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_CUSTOM_BORDER_COLOR_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceCustomBorderColorFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceCustomBorderColorFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIVATE_DATA_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDevicePrivateDataFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePrivateDataFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_PRIVATE_DATA_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkDevicePrivateDataCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkDevicePrivateDataCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PIPELINE_CREATION_CACHE_CONTROL_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePipelineCreationCacheControlFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DIAGNOSTICS_CONFIG_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDiagnosticsConfigFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDiagnosticsConfigFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_DEVICE_DIAGNOSTICS_CONFIG_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkDeviceDiagnosticsConfigCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkDeviceDiagnosticsConfigCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentShadingRateEnumsFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_SHADING_RATE_ENUMS_PROPERTIES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentShadingRateEnumsPropertiesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_FRAGMENT_SHADING_RATE_ENUM_STATE_CREATE_INFO_NV:
            {
                pnext.resize(sizeof(VkPipelineFragmentShadingRateEnumStateCreateInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineFragmentShadingRateEnumStateCreateInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_GEOMETRY_MOTION_TRIANGLES_DATA_NV:
            {
                pnext.resize(sizeof(VkAccelerationStructureGeometryMotionTrianglesDataNV));
                std::memcpy(pnext.data(), base, sizeof(VkAccelerationStructureGeometryMotionTrianglesDataNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_ACCELERATION_STRUCTURE_MOTION_INFO_NV:
            {
                pnext.resize(sizeof(VkAccelerationStructureMotionInfoNV));
                std::memcpy(pnext.data(), base, sizeof(VkAccelerationStructureMotionInfoNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_MOTION_BLUR_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRayTracingMotionBlurFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_YCBCR_2_PLANE_444_FORMATS_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceYcbcr2Plane444FormatsFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentDensityMap2FeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_FRAGMENT_DENSITY_MAP_2_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceFragmentDensityMap2PropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_COPY_COMMAND_TRANSFORM_INFO_QCOM:
            {
                pnext.resize(sizeof(VkCopyCommandTransformInfoQCOM));
                std::memcpy(pnext.data(), base, sizeof(VkCopyCommandTransformInfoQCOM));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_IMAGE_ROBUSTNESS_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceImageRobustnessFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceImageRobustnessFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_4444_FORMATS_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDevice4444FormatsFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevice4444FormatsFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RGBA10X6_FORMATS_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRGBA10X6FormatsFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MUTABLE_DESCRIPTOR_TYPE_FEATURES_VALVE:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMutableDescriptorTypeFeaturesVALVE));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_MUTABLE_DESCRIPTOR_TYPE_CREATE_INFO_VALVE:
            {
                pnext.resize(sizeof(VkMutableDescriptorTypeCreateInfoVALVE));
                std::memcpy(pnext.data(), base, sizeof(VkMutableDescriptorTypeCreateInfoVALVE));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_VERTEX_INPUT_DYNAMIC_STATE_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceVertexInputDynamicStateFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_DRM_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceDrmPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceDrmPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PRIMITIVE_TOPOLOGY_LIST_RESTART_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePrimitiveTopologyListRestartFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_IMPORT_MEMORY_ZIRCON_HANDLE_INFO_FUCHSIA:
            {
                pnext.resize(sizeof(VkImportMemoryZirconHandleInfoFUCHSIA));
                std::memcpy(pnext.data(), base, sizeof(VkImportMemoryZirconHandleInfoFUCHSIA));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_INVOCATION_MASK_FEATURES_HUAWEI:
            {
                pnext.resize(sizeof(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceInvocationMaskFeaturesHUAWEI));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTERNAL_MEMORY_RDMA_FEATURES_NV:
            {
                pnext.resize(sizeof(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceExternalMemoryRDMAFeaturesNV));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_EXTENDED_DYNAMIC_STATE_2_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceExtendedDynamicState2FeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_COLOR_WRITE_ENABLE_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceColorWriteEnableFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceColorWriteEnableFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PIPELINE_COLOR_WRITE_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkPipelineColorWriteCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPipelineColorWriteCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_GLOBAL_PRIORITY_QUERY_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceGlobalPriorityQueryFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_QUEUE_FAMILY_GLOBAL_PRIORITY_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkQueueFamilyGlobalPriorityPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkQueueFamilyGlobalPriorityPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMultiDrawFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMultiDrawFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_MULTI_DRAW_PROPERTIES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceMultiDrawPropertiesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceMultiDrawPropertiesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_BORDER_COLOR_SWIZZLE_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceBorderColorSwizzleFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_SAMPLER_BORDER_COLOR_COMPONENT_MAPPING_CREATE_INFO_EXT:
            {
                pnext.resize(sizeof(VkSamplerBorderColorComponentMappingCreateInfoEXT));
                std::memcpy(pnext.data(), base, sizeof(VkSamplerBorderColorComponentMappingCreateInfoEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_PAGEABLE_DEVICE_LOCAL_MEMORY_FEATURES_EXT:
            {
                pnext.resize(sizeof(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDevicePageableDeviceLocalMemoryFeaturesEXT));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET_ACCELERATION_STRUCTURE_KHR:
            {
                pnext.resize(sizeof(VkWriteDescriptorSetAccelerationStructureKHR));
                std::memcpy(pnext.data(), base, sizeof(VkWriteDescriptorSetAccelerationStructureKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceAccelerationStructureFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceAccelerationStructureFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_ACCELERATION_STRUCTURE_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceAccelerationStructurePropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceAccelerationStructurePropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRayTracingPipelineFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRayTracingPipelineFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_TRACING_PIPELINE_PROPERTIES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRayTracingPipelinePropertiesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRayTracingPipelinePropertiesKHR));
                ret.emplace_back(pnext);
                break;
            }
        case VK_STRUCTURE_TYPE_PHYSICAL_DEVICE_RAY_QUERY_FEATURES_KHR:
            {
                pnext.resize(sizeof(VkPhysicalDeviceRayQueryFeaturesKHR));
                std::memcpy(pnext.data(), base, sizeof(VkPhysicalDeviceRayQueryFeaturesKHR));
                ret.emplace_back(pnext);
                break;
            }
        }
        base = base->pNext;
    }
    auto size = ret.size();
    for(size_t i = 1 ; i < size ; ++i)
    {
        auto pnext = reinterpret_cast<VkBaseInStructure*>(ret[i].data());
        auto last_pnext = reinterpret_cast<VkBaseInStructure*>(ret[i-1].data());
        last_pnext->pNext = pnext;
    }
    return std::move(ret);
}

GFXRECON_END_NAMESPACE(encode)
GFXRECON_END_NAMESPACE(gfxrecon)
