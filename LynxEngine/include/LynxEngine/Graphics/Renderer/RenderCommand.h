#pragma once

#include "LynxEngine/Graphics/Renderer/RendererAPI.h"
#include "LynxEngine/Core.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	class RenderCommand
	{
		public:
			inline static void init(Window *window)
			{
				getAPI()->init(window);
			}

			inline static void draw()
			{
				getAPI()->draw();
			}

			inline static void setCamera(Camera &cam)
			{
				getAPI()->setCamera(cam);
			}

			inline static void recreateSwapchain()
			{
				getAPI()->recreateSwapchain();
			}

			static void cleanup();
			static RendererAPI *getAPI();
		private:
	};
}
