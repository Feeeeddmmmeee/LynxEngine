#ifndef APPLICATION_H
#define APPLICATION_H

#include "LayerManager.h"

#include <string>

namespace Lynx
{
	class Application
	{
		public:
			Application(std::string name, unsigned int windowWidth, unsigned int windowHeight);
			~Application();

			void run();
			void close();
			bool isRunning();

			LayerManager layerManager;

		private:
			std::string name;
			unsigned int windowWidth, windowHeight;
			bool running = 0;
	};
}

#endif
