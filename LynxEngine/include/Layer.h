#ifndef LAYER_H
#define LAYER_H

namespace Lynx
{
	class Layer
	{
		public:
			virtual ~Layer() = default;

			virtual void onUpdate() {};
			virtual void onRender() {};

			void queueTransition(Layer *layer);

		private:
	};
}

#endif
