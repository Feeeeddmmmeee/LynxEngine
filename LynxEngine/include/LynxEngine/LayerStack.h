#pragma once

#include "LynxEngine/Layer.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	class LayerStack
	{
		public:
			template<typename TLayer, typename... Args>
			void pushLayer(Args&&... args)
			{
				auto layer = new TLayer(std::forward<Args>(args)...);
				layer->init(this);

				updateQueue.push([this, layer]() {
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
					for(auto it = this->layers.begin(); it != this->layers.end(); ++it)
					{
						if(dynamic_cast<TLayer*>(it->get()))
						{
							it->get()->onDetach();
							this->layers.erase(it);
							return;
						}
					}
				});
			}

			template<typename TLayer, typename TNewLayer, typename... Args>
			void swapLayer(Args&&... args)
			{
				auto layer = new TNewLayer(std::forward<Args>(args)...);
				layer->init(this);

				updateQueue.push([this, layer]() {
					for(auto it = this->layers.begin(); it != this->layers.end(); ++it)
					{
						if(dynamic_cast<TLayer*>(it->get()))
						{
							it->get()->onDetach();
							*(it) =  std::move(std::unique_ptr<TNewLayer>(layer));
							layer->onAttach();
							return;
						}
					}

					// Delete the layer if no layer to transition from was found
					LYNX_ENGINE_INFO("Failed to swap {0} to {1}, no {0} layer exists!", typeid(TLayer).name(), typeid(TNewLayer).name());
					delete layer;
				});
			}

		private:
			friend class Application;
			std::vector<std::unique_ptr<Layer>> layers;
			std::queue<std::function<void()>> updateQueue;

			void handleEvent(Event *event);
			void updateLayers(Timestep dt);
			void processOperations();
	};
}
