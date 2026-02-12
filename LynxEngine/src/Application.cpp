#include "LynxEngine/Application.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	void Application::run()
	{
		LYNX_ENGINE_DEBUG("Initializing {}...", this->name);
		queueEvent(new Lynx::Event());

		// temporary to stop infinite loops
		int i = 0;
		while(this->isRunning() && i < 5000000)
		{
			this->updateLayers();
			this->handleEvents();
			++i;
		}

		LYNX_ENGINE_DEBUG("Closing {}...", this->name);
	}

	void Application::queueEvent(Lynx::Event *event)
	{
		this->eventQueue.push(event);
	}

	void Application::handleEvents()
	{
		while(!this->eventQueue.empty())
		{
			auto e = this->eventQueue.front();
			LYNX_ENGINE_DEBUG("Handling event: {}", typeid(e).name());
			for(auto it = this->layers.end(); it != this->layers.begin();)
			{
				(*--it)->onEvent(e);
				if(e->handled) break;
			}
			delete e;
			this->eventQueue.pop();
		}
	}

	void Application::close()
	{
		this->running = 0;
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
