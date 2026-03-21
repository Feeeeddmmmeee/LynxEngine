#pragma once

#include "LynxEngine/Graphics/Window.h"

namespace Lynx
{
	class RendererAPI
	{
		public:
			virtual ~RendererAPI() = default;

			virtual void init(Window *window) = 0;
			virtual void draw() = 0;
			virtual void cleanup() = 0;

			static RendererAPI *create();
	};
}
