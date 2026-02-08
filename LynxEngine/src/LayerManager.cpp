#include "LayerManager.h"

namespace Lynx
{
	void LayerManager::updateLayers()
	{
		for(auto &layer : this->layers)
		{
			layer->update();
		}

		for(auto &layer : this->layers)
		{
			layer->render();
		}
	}

	void LayerManager::processLayerEvents()
	{

	}
}
