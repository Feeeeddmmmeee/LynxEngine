#include "LayerManager.h"

namespace Lynx
{
	void LayerManager::update()
	{
		for(auto &layer : this->layers)
		{
			layer->update();
		}

		for(int i = 0; i < this->layers.size(); ++i)
		{
			auto &next = layers[i]->nextLayer;
			if(next)
			{
				layers[i] = std::move(next);
			}
		}

		for(auto &layer : this->layers)
		{
			layer->render();
		}
	}
}
