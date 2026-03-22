#pragma once

#include "LynxEngine/Graphics/Renderer/RendererAPI.h"
#include "LynxEngine/Core.h"

namespace Lynx
{
	class RenderCommand
	{
		public:
			inline static void init(Window *window)
			{
				rendererAPI->init(window);
			}

			inline static void draw()
			{
				rendererAPI->draw();
			}

			inline static void cleanup()
			{
				rendererAPI->cleanup();
			}

			inline static void recreateSwapchain()
			{
				rendererAPI->recreateSwapchain();
			}
		private:
			static Scope<RendererAPI> rendererAPI;
	};
}
