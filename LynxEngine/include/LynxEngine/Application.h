#pragma once

#include "LynxEngine/LayerStack.h"
#include "LynxEngine/Graphics/Window.h"

#include <string>

namespace Lynx
{
	class Application
	{
		public:
			Application(const WindowSpec &winSpec = WindowSpec());
			~Application();

			void run();
			void queueEvent(Lynx::Event *event);

			void close();
			bool isRunning() { return this->running; };
			
			template<typename TLayer, typename... Args>
			void pushLayer(Args&&... args)
			{
				this->layerStack.pushLayer<TLayer>(std::forward<Args>(args)...);
			}

		private:
			bool running = 0;
			std::queue<Lynx::Event*> eventQueue;
			Lynx::LayerStack layerStack;
			Lynx::Window *window;

			void handleEvents();

			// Temporary
			std::string name;
	};
}
