#ifndef LAYER_MANAGER_H
#define LAYER_MANAGER_H

#include "Layer.h"

#include <memory>
#include <vector>

namespace Lynx
{
	class LayerManager
	{
		public:
			void update();

			template<typename TLayer>
			void pushLayer()
			{
				this->layers.push_back(std::make_unique<TLayer>());
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
				for(int i = 0; i < this->layers.size(); ++i)
				{
					if(auto casted = dynamic_cast<TLayer*>(this->layers[i].get()))
					{
						break;
					}
				}
			}

		private:
			std::vector<std::unique_ptr<Layer>> layers;
	};
}

#endif
