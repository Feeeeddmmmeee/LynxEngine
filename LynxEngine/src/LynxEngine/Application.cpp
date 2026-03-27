#include "LynxEngine/Application.h"
#include "LynxEngine/Events/EventDispatcher.h"
#include "LynxEngine/Events/WindowEvents.h"
#include "LynxEngine/Events/KeyboardEvents.h"
#include "LynxEngine/Logging.h"
#include "LynxEngine/Graphics/Renderer/RenderCommand.h"

namespace Lynx
{
	void Application::run()
	{
		running = 1;
		while(this->isRunning())
		{
			Timestep dt = clock.tick();
			this->window->update();
			this->layerStack.updateLayers(dt);

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

			Lynx::EventDispatcher dispatcher = Lynx::EventDispatcher(event);
			dispatcher.dispatch<WindowCloseEvent>([this](){ this->close(); });
			dispatcher.dispatch<WindowResizeEvent>([this](){ RenderCommand::recreateSwapchain(); });
			dispatcher.dispatch<KeyPressedEvent>([this](KeyPressedEvent *e){
					if(e->getKey() == Keycode::ESCAPE)
						window->toggleMouseVisibility();
				});

			this->layerStack.handleEvent(event);
			delete event;
			this->eventQueue.pop();
		}
	}

	void Application::close()
	{
		this->running = 0;
	}

	Application::Application(const WindowSpec &spec)
	{
		this->name = spec.name;
		this->window = Window::create(spec);
		LYNX_ENGINE_DEBUG("Initializing {}...", name);

		this->window->setEventCallback([this](Lynx::Event *e){
				this->queueEvent(e);
		});
	}

	Application::~Application()
	{
		LYNX_ENGINE_DEBUG("Closing {}...", this->name);

		while(!this->eventQueue.empty())
		{
			delete this->eventQueue.front();
			this->eventQueue.pop();
		}
	}
}
