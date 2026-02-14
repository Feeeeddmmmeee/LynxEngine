#include "LynxEngine/Application.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	void Application::run()
	{
		LYNX_ENGINE_DEBUG("Initializing {}...", this->name);

		// temporary to stop infinite loops
		int i = 0;
		while(this->isRunning() && i < 5000000)
		{
			this->layerStack.updateLayers();
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
			auto event = this->eventQueue.front();
			LYNX_ENGINE_DEBUG("Handling event: {}", typeid(event).name());
			this->layerStack.handleEvent(event);
			delete event;
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
