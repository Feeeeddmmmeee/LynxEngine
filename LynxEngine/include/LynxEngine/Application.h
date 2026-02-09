#pragma once

#include "LynxEngine/LayerManager.h"

#include <string>

namespace Lynx
{
	class Application : public LayerManager
	{
		public:
			Application(std::string name, unsigned int windowWidth, unsigned int windowHeight);
			~Application();

			void run();
			void close();
			bool isRunning();

		private:
			bool running = 0;

			// Temporary
			std::string name;
			unsigned int windowWidth, windowHeight;
	};
}
