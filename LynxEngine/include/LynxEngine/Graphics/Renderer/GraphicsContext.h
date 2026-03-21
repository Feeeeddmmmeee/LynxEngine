#pragma once

#include "LynxEngine/Core.h"

namespace Lynx
{
	class GraphicsContext
	{
		public:
			virtual ~GraphicsContext() = default;
			virtual void init() = 0;

			static Scope<GraphicsContext> create();
	};
}
