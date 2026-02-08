#pragma once

#include "Layer.h"

#include <memory>
#include <vector>

namespace Lynx
{
	class LayerManager
	{
		public:
			template<typename TLayer>
			void pushLayer()
			{
				auto layer = std::make_unique<TLayer>();
				layer->init(this);
				this->layers.push_back(std::move(layer));
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
				// TODO
			}

		protected:
			void updateLayers();
			void processLayerEvents();

		private:
			std::vector<std::unique_ptr<Layer>> layers;
	};
}
