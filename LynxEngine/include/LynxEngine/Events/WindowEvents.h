#pragma once

#include "LynxEngine/Events/Event.h"

namespace Lynx
{
	class WindowClose : public Event
	{
		public:
			DECL_EVENT_METHODS(WindowClose)
	};
}
