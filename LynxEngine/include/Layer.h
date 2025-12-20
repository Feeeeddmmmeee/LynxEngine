#ifndef LAYER_H
#define LAYER_H

#include <memory>

namespace Lynx
{
	class Layer
	{
		public:
			virtual ~Layer() = default;

			virtual void update() {};
			virtual void render() {};

			template<typename TLayer>
			void queueTransition()
			{
				this->nextLayer = std::move(std::make_unique<TLayer>());
			}

		private:
			friend class LayerManager;
			std::unique_ptr<Layer> nextLayer = nullptr;
	};
}

#endif
