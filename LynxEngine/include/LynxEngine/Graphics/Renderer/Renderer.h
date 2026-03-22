#pragma once

#include "LynxEngine/Graphics/Camera.h"
#include "LynxEngine/Graphics/Window.h"

namespace Lynx
{
	class Renderer
	{
		public:
			static void init(Window *window);
			static void beginScene(Camera &camera);
			static void submit();
			static void endScene();
			static void cleanup();
	};
}
