#include "LynxEngine/LayerStack.h"

namespace Lynx
{
	void LayerStack::updateLayers(Timestep dt)
	{
		this->processOperations();
		for(auto &layer : this->layers)
		{
			layer->onUpdate(dt);
		}
	}

	void LayerStack::processOperations()
	{
		while(!this->updateQueue.empty())
		{
			auto &op = this->updateQueue.front();
			op();
			this->updateQueue.pop();
		}
	}

	void LayerStack::handleEvent(Lynx::Event *event)
	{
		for(auto it = this->layers.end(); it != this->layers.begin();)
		{
			if(event->handled) break;
			(*--it)->onEvent(event);
		}
	}
}
