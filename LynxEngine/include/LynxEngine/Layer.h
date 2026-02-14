#pragma once

#include "LynxEngine/Events/Event.h"

namespace Lynx
{
	class LayerStack;
	class Layer
	{
		public:
			virtual ~Layer() = default;

			virtual void onAttach() {};
			virtual void onUpdate() {};
			virtual void onEvent(Lynx::Event *event) {};
			virtual void onDetach() {};

		protected:
			inline LayerStack* getManager() const { return this->layerStack; };

		private:
			friend class LayerStack;
			LayerStack *layerStack;

			void init(LayerStack *manager);
	};
}
