#include "LayerManager.h"

namespace Lynx
{
	void LayerManager::updateLayers()
	{
		this->processOperations();
		for(auto &layer : this->layers)
		{
			layer->onUpdate();
		}
	}

	void LayerManager::processOperations()
	{
		while(!this->updateQueue.empty())
		{
			auto &op = this->updateQueue.front();
			op();
			this->updateQueue.pop();
		}
	}
}
