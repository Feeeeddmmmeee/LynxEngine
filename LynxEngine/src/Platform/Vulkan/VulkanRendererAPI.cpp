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
		setupObjects();
		createUniformBuffers();
		createDescPool();
		createDescSets();
		createCommandBuffers();
		createSyncObjects();
	}

	void VulkanRendererAPI::recreateSwapchain()
	{
		device.waitIdle();

		cleanupSwapchain();
		createSwapchain();
		createSwapchainImageViews();
		createColorResources();
		createDepthResources();
	}

	void VulkanRendererAPI::setCamera(Camera &cam)
	{
		this->camera = &cam;
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
