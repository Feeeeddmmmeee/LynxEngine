#pragma once

#include "LynxEngine/Layer.h"
#include "LynxEngine/Logging.h"

#include <memory>
#include <utility>
#include <vector>
#include <queue>
#include <functional>

namespace Lynx
{
	class LayerManager
	{
		public:
			template<typename TLayer, typename... Args>
			void pushLayer(Args&&... args)
			{
				auto layer = new TLayer(std::forward<Args>(args)...);
				layer->init(this);

				updateQueue.push([this, layer]() {
					LYNX_ENGINE_DEBUG("PUSH");
					this->layers.push_back(std::move(std::unique_ptr<Layer>(layer)));
					layer->onAttach();
				});
			}

			template<typename TLayer>
			Layer *getLayer()
			{
				for(auto &layer : this->layers)
				{
					if(auto casted = dynamic_cast<TLayer*>(layer.get()))
						return casted;
				}
				return nullptr;
			}

			template<typename TLayer>
			void removeLayer()
			{
				updateQueue.push([this]() {
					LYNX_ENGINE_DEBUG("REMOVE");
					for(auto it = this->layers.begin(); it != this->layers.end(); ++it)
					{
						if(dynamic_cast<TLayer*>(it->get()))
						{
							LYNX_ENGINE_DEBUG("	FOUND!");
							it->get()->onDetach();
							this->layers.erase(it);
							return;
						}
					}
				});
			}

		protected:
			void updateLayers();

		private:
			std::vector<std::unique_ptr<Layer>> layers;
			std::queue<std::function<void()>> updateQueue;

			void processOperations();
	};
}
