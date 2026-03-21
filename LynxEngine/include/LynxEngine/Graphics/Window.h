#pragma once

#include "LynxEngine/Events/Event.h"

#include <functional>
#include <string>

namespace Lynx
{
	struct WindowSpec
	{
		std::string name="Lynx App";
		int width=1080;
		int height=720;
		bool fullscreen=false;
		bool resizable=true;
	};

	class Window
	{
		public:
			virtual ~Window() = default;

			virtual void setEventCallback(std::function<void(Lynx::Event*)> callback) = 0;
			virtual void update() = 0;
			virtual void setFullscreen(bool fullscreen) = 0;
			virtual void setResizable(bool resizable) = 0;
			virtual void setTitle(std::string name) = 0;

			const WindowSpec &getWinSpec() { return this->spec; }

			static Window *create(const WindowSpec &spec);

		protected:
			WindowSpec spec;
	};
}
