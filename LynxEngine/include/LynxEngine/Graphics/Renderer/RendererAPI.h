#pragma once

#include "LynxEngine/Graphics/Window.h"
#include "LynxEngine/Graphics/Camera.h"

namespace Lynx
{
	class RendererAPI
	{
		public:
			virtual ~RendererAPI() = default;

			virtual void init(Window *window) = 0;
			virtual void draw() = 0;
			virtual void setCamera(Camera &cam) = 0;
			virtual void cleanup() = 0;
			virtual void recreateSwapchain() = 0;

			static RendererAPI *create();
	};
}
