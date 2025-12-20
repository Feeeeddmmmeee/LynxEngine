#include "Application.h"
#include <iostream>
#include <SDL3/SDL.h>

namespace Lynx
{
	void Application::run()
	{
		// TEMPORARY!!! Just to have a something to test other systems
		std::cout<<"Initializing "<<this->name<<"..."<<std::endl;

		SDL_Init(SDL_INIT_VIDEO);
		SDL_Window *window = SDL_CreateWindow(this->name.c_str(), this->windowWidth, this->windowHeight, SDL_WINDOW_RESIZABLE);
		SDL_Renderer *renderer = SDL_CreateRenderer(window, NULL);
		while(this->isRunning())
		{
			SDL_RenderClear(renderer);
			this->layerManager.update();
			SDL_RenderPresent(renderer);
			SDL_Delay(5000);
			this->close();
		}

		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		std::cout<<"Closing "<<this->name<<"..."<<std::endl;
	}

	void Application::close()
	{
		this->running = 0;
	}

	bool Application::isRunning()
	{
		return this->running;
	}

	Application::Application(std::string name, int windowWidth, int windowHeight)
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
