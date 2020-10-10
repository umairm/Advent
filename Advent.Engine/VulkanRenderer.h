#pragma once

#include <vulkan/vulkan.h>

namespace Advent {
	class Platform;

	class VulkanRenderer {
	public:
		VulkanRenderer(Platform* platform);
		~VulkanRenderer();

	private:
		Platform* _platform;
	};
}