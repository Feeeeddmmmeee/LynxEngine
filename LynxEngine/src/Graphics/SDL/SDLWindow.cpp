#include "LynxEngine/Graphics/SDL/SDLWindow.h"
#include "LynxEngine/Events/WindowEvents.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	static bool initializedSDL = 0;

	// TEMPORARY !!!
	static SDL_Renderer *renderer;

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
				case SDL_EVENT_QUIT:
					this->eventCallback(new WindowCloseEvent());
					break;
				case SDL_EVENT_WINDOW_RESIZED:
					this->eventCallback(new WindowResizeEvent(e.window.data1, e.window.data2));
					break;
				case SDL_EVENT_WINDOW_MOVED:
					this->eventCallback(new WindowMoveEvent(e.window.data1, e.window.data2));
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
