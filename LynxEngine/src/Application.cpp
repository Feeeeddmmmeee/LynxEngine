#include "Application.h"
#include "Logging.h"
#include <iostream>
#include <SDL3/SDL.h>

namespace Lynx
{
	void Application::run()
	{
		// TEMPORARY!!! Just to have a something to test other systems
		LYNX_ENGINE_DEBUG("Initializing {}...", this->name);

		// SDL_Init(SDL_INIT_VIDEO);
		// SDL_Window *window = SDL_CreateWindow(this->name.c_str(), this->windowWidth, this->windowHeight, SDL_WINDOW_RESIZABLE);
		// SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
		//
		int i = 0;
		while(this->isRunning() && i < 50000)
		{
		// 	SDL_RenderClear(renderer);
			this->updateLayers();
		// 	SDL_RenderPresent(renderer);
			++i;
		}
		//
		// SDL_DestroyRenderer(renderer);
		// SDL_DestroyWindow(window);
		// SDL_Quit();
		LYNX_ENGINE_DEBUG("Closing {}...", this->name);
	}

	void Application::close()
	{
		this->running = 0;
	}

	bool Application::isRunning()
	{
		return this->running;
	}

	Application::Application(std::string name, unsigned int windowWidth, unsigned int windowHeight)
	{
		this->name = name;
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;

		this->running = 1;
	}

	Application::~Application()
	{

	}
}
