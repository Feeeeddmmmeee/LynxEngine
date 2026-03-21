#include "Platform/Vulkan/VulkanRendererAPI.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	RendererAPI *RendererAPI::create()
	{
		return new VulkanRendererAPI();
	}

	void VulkanRendererAPI::init(Window *window)
	{
		LYNX_ENGINE_DEBUG("Initializing Vulkan...");
		this->window = window;
		createInstance();
		setupDebugMessenger();
		createSurface();
		pickPhysicalDevice();
		createLogicalDevice();
		createSwapchain();
		createSwapchainImageViews();
		createDescSetLayout();
		setupPipelineManager();
		createCommandPool();
		createColorResources();
		createDepthResources();
		setupCamera();
		setupObjects();
		createUniformBuffers();
		createDescPool();
		createDescSets();
		createCommandBuffers();
		createSyncObjects();
	}

	void VulkanRendererAPI::draw()
	{
		drawFrame();
	}

	void VulkanRendererAPI::cleanup()
	{
		cleanupSwapchain();
	}

	VulkanRendererAPI::~VulkanRendererAPI()
	{
		device.waitIdle();
		cleanup();
	}
}
