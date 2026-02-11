#pragma once

namespace Lynx
{
	class LayerManager;
	class Layer
	{
		public:
			virtual ~Layer() = default;

			virtual void onAttach() {};
			virtual void onUpdate() {};
			virtual void onDetach() {};

		protected:
			inline LayerManager* getManager() const { return this->layerManager; };

		private:
			friend class LayerManager;
			LayerManager *layerManager;

			void init(LayerManager *manager);
	};
}
