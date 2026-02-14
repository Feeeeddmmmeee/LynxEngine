#pragma once

#include "LynxEngine/Graphics/Window.h"

#include <SDL3/SDL.h>
#include <string>

namespace Lynx
{
	class SDLWindow : public Window
	{
		public:
			SDLWindow(std::string, int width, int height);
			~SDLWindow();

			void update() override;
			void setEventCallback(std::function<void(Lynx::Event*)> callback) override;

		private:
			std::function<void(Lynx::Event*)> eventCallback;
			SDL_Window *window;

			void pollSDLEvents();
	};
}
