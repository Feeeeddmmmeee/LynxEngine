#pragma once

#include "LynxEngine/Events/Event.h"

namespace Lynx
{
	class LayerManager;
	class Layer
	{
		public:
			virtual ~Layer() = default;

			virtual void onAttach() {};
			virtual void onUpdate() {};
			virtual void onEvent(Lynx::Event *event) {};
			virtual void onDetach() {};

		protected:
			inline LayerManager* getManager() const { return this->layerManager; };

		private:
			friend class LayerManager;
			LayerManager *layerManager;

			void init(LayerManager *manager);
	};
}
