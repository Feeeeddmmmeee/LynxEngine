#pragma once

#include "LynxEngine/Graphics/Window.h"

#include <SDL3/SDL.h>

namespace Lynx
{

	class SDLWindow : public Window
	{
		public:
			SDLWindow(const WindowSpec&);
			~SDLWindow();

			void update() override;
			void setEventCallback(std::function<void(Lynx::Event*)> callback) override;
			void setFullscreen(bool fullscreen) override;
			void setResizable(bool resizable) override;
			void setTitle(std::string name) override;

		private:
			std::function<void(Lynx::Event*)> eventCallback;
			SDL_Window *window;

			void pollSDLEvents();
	};
}
