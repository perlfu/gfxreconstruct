
/*
** Copyright (c) 2022 LunarG, Inc.
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

#ifndef GFXRECON_GRAPHICS_VULKAN_DEVICE_ADDRESS_MAP_H
#define GFXRECON_GRAPHICS_VULKAN_DEVICE_ADDRESS_MAP_H

#include "format/format.h"
#include "util/defines.h"

#include "vulkan/vulkan.h"

#include <map>

GFXRECON_BEGIN_NAMESPACE(gfxrecon)
GFXRECON_BEGIN_NAMESPACE(graphics)

class VkDeviceAddressMap
{
  public:
    void Add(format::HandleId resource_id,
             VkDeviceAddress  old_start_address,
             VkDeviceSize     old_size,
             VkDeviceAddress  new_start_address);

    void Remove(format::HandleId resource_id, VkDeviceAddress old_start_address);

    VkDeviceAddress
    Map(VkDeviceAddress old_address, format::HandleId* resource_id = nullptr, bool* found = nullptr) const;

  private:
    struct VkDeviceAddressInfo
    {
        VkDeviceAddress old_end_address{ 0 };
        VkDeviceAddress new_start_address{ 0 };
    };

    typedef std::map<format::HandleId, VkDeviceAddressInfo>                                 AliasedResourceVaInfo;
    typedef std::map<VkDeviceAddress, AliasedResourceVaInfo, std::greater<VkDeviceAddress>> DevAddrMap;

  private:
    bool FindMatch(const AliasedResourceVaInfo& resource_info,
                   VkDeviceAddress              old_start_address,
                   VkDeviceAddress&             address,
                   format::HandleId*            resource_id) const;

  private:
    DevAddrMap dev_addr_map_;
};

GFXRECON_END_NAMESPACE(graphics)
GFXRECON_END_NAMESPACE(gfxrecon)

#endif // GFXRECON_GRAPHICS_VULKAN_DEVICE_ADDRESS_MAP_H
