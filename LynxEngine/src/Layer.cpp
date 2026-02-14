#include "LynxEngine/Layer.h"

namespace Lynx
{
	void Layer::init(LayerStack *manager)
	{
		this->layerStack = manager;
	}
}
