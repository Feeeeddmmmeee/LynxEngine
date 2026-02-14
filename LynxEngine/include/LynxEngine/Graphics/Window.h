#pragma once

#include "LynxEngine/Events/Event.h"

#include <functional>

namespace Lynx
{
	class Window
	{
		public:
			virtual ~Window() = default;

			virtual void update() = 0;
			virtual void setEventCallback(std::function<void(Lynx::Event*)> callback) = 0;

			static Window *create();
	};
}
