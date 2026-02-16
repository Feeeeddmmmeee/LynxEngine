#include "LynxEngine/Graphics/SDL/SDLWindow.h"
#include "LynxEngine/Events/WindowEvents.h"
#include "LynxEngine/Events/KeyboardEvents.h"
#include "LynxEngine/Events/MouseEvents.h"
#include "LynxEngine/Logging.h"

#include <SDL3/SDL_events.h>
#include <SDL3/SDL_mouse.h>

// TEMPORARY !!!
SDL_Renderer *renderer;

namespace Lynx
{
	static bool initializedSDL = 0;

	Window *Window::create(const WindowSpec &spec)
	{
		return new SDLWindow(spec);
	}

	void SDLWindow::update()
	{
		// TEMPORARY !!!
		SDL_RenderClear(renderer);
		SDL_RenderPresent(renderer);

		this->pollSDLEvents();
	}

	void SDLWindow::setEventCallback(std::function<void(Event*)> callback)
	{
		this->eventCallback = callback;
	}

	void SDLWindow::pollSDLEvents()
	{
		SDL_Event e;
		while(SDL_PollEvent(&e))
		{
			switch(e.type)
			{
				// WINDOW EVENTS
				case SDL_EVENT_QUIT:
					this->eventCallback(new WindowCloseEvent());
					break;
				case SDL_EVENT_WINDOW_RESIZED:
					this->eventCallback(new WindowResizeEvent(e.window.data1, e.window.data2));
					break;
				case SDL_EVENT_WINDOW_MOVED:
					this->eventCallback(new WindowMoveEvent(e.window.data1, e.window.data2));
					break;
				case SDL_EVENT_WINDOW_ENTER_FULLSCREEN:
					this->eventCallback(new WindowEnterFullscreenEvent());
					break;
				case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN:
					this->eventCallback(new WindowExitFullscreenEvent());
					break;
				case SDL_EVENT_WINDOW_FOCUS_GAINED:
					this->eventCallback(new WindowEnterFocusEvent());
					break;
				case SDL_EVENT_WINDOW_FOCUS_LOST:
					this->eventCallback(new WindowExitFocusEvent());
					break;

				// KEYBOARD EVENTS
				case SDL_EVENT_KEY_DOWN:
					if(e.key.repeat)
						this->eventCallback(new KeyRepeatEvent((Keycode)e.key.key));
					else
						this->eventCallback(new KeyPressedEvent((Keycode)e.key.key));
					break;
				case SDL_EVENT_KEY_UP:
					this->eventCallback(new KeyReleasedEvent((Keycode)e.key.key));
					break;

				// MOUSE EVENTS
				case SDL_EVENT_MOUSE_MOTION:
					this->eventCallback(new MouseMoveEvent(e.motion.x, e.motion.y));
					break;
				case SDL_EVENT_MOUSE_WHEEL:
					this->eventCallback(new MouseScrollEvent(e.wheel.x, e.wheel.y));
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					this->eventCallback(new MouseButtonPressedEvent((Mousecode)e.button.button));
					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					this->eventCallback(new MouseButtonReleasedEvent((Mousecode)e.button.button));
					break;
				default:
					break;
			}
		}
	}

	SDLWindow::SDLWindow(const WindowSpec &spec)
	{
		this->spec = spec;
		if(!initializedSDL)
		{
			SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
			SDL_SetLogOutputFunction([](void*, int, SDL_LogPriority, const char* msg){
				LYNX_ENGINE_DEBUG(msg);
			}, 0);

			LYNX_ENGINE_DEBUG("Initializing SDL...");
			SDL_Init(SDL_INIT_VIDEO);
			initializedSDL = 1;
		}

		unsigned long flags = 0;
		if(spec.fullscreen) flags |= SDL_WINDOW_FULLSCREEN;
		if(spec.resizable) flags |= SDL_WINDOW_RESIZABLE;

		LYNX_ENGINE_DEBUG("Creating SDL Window...");
		this->window = SDL_CreateWindow(spec.name.c_str(), spec.width, spec.height, flags);
		if(this->window == NULL) LYNX_ENGINE_ERROR("Failed to create SDL Window!");

		// TEMPORARY !!!
		renderer = SDL_CreateRenderer(this->window, NULL);
	}

	SDLWindow::~SDLWindow()
	{
		SDL_DestroyWindow(this->window);
	}
	
	void SDLWindow::setFullscreen(bool fullscreen)
	{
		SDL_SetWindowFullscreen(this->window, fullscreen);
	}

	void SDLWindow::setResizable(bool resizable)
	{
		SDL_SetWindowResizable(this->window, resizable);
	}

	void SDLWindow::setTitle(std::string title)
	{
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}
