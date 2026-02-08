#pragma once

#include <memory>

namespace Lynx
{
	class LayerManager;
	class Layer
	{
		public:
			virtual ~Layer() = default;

			virtual void update() {};
			virtual void render() {};

			template<typename TLayer>
			void queueTransition()
			{
				//TODO
			}

		protected:
			inline LayerManager* getManager() const { return this->layerManager; };

		private:
			friend class LayerManager;
			LayerManager *layerManager;

			void init(LayerManager *manager);
	};
}
