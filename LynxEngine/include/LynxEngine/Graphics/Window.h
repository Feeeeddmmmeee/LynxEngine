#pragma once

#include "LynxEngine/Events/Event.h"

#include <functional>
#include <string>

namespace Lynx
{
	struct WindowSpec
	{
		std::string name;
		int width;
		int height;
		bool fullscreen;
		bool resizable;

		WindowSpec(const std::string &n="Lynx App", int w=1080, int h=720, bool f=0, bool r=1) :
			name(n), width(w), height(h), fullscreen(f), resizable(r) {}
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
