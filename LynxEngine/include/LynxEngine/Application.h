#pragma once

#include "LynxEngine/LayerStack.h"

#include <string>

namespace Lynx
{
	class Application
	{
		public:
			Application(std::string name="Lynx App", unsigned int windowWidth=640, unsigned int windowHeight=480);
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

			void handleEvents();

			// Temporary
			std::string name;
			unsigned int windowWidth, windowHeight;
	};
}
