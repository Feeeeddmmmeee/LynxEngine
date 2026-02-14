#include "LynxEngine/Application.h"
#include "LynxEngine/Events/EventDispatcher.h"
#include "LynxEngine/Events/WindowEvents.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	void Application::run()
	{
		while(this->isRunning())
		{
			this->window->update();
			this->layerStack.updateLayers();

			this->handleEvents();
		}
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

			Lynx::EventDispatcher dispatcher = Lynx::EventDispatcher(event);
			dispatcher.dispatch<WindowCloseEvent>([this](Lynx::Event*){ this->close(); return 1; });

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
		LYNX_ENGINE_DEBUG("Initializing {}...", name);

		this->name = name;
		this->windowWidth = windowWidth;
		this->windowHeight = windowHeight;

		this->window = Window::create();
		this->window->setEventCallback([this](Lynx::Event *e){
				this->queueEvent(e);
		});

		this->running = 1;
	}

	Application::~Application()
	{
		LYNX_ENGINE_DEBUG("Closing {}...", this->name);

		delete this->window;
	}
}
