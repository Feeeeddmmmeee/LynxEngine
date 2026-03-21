#pragma once

#include "LynxEngine/Graphics/PerspectiveCamera.h"
#include "LynxEngine/Graphics/Window.h"

namespace Lynx
{
	class Renderer
	{
		public:
			static void init(Window *window);
			static void beginScene(PerspectiveCamera &camera);
			static void submit();
			static void endScene();
			static void cleanup();
	};
}
