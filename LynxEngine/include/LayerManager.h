#ifndef LAYER_MANAGER_H
#define LAYER_MANAGER_H

#include "Layer.h"

#include <vector>

namespace Lynx
{
	class LayerManager
	{
		public:
			void pushLayer(Layer *layer);

		private:
			std::vector<Layer*> layers;
	};
}

#endif
