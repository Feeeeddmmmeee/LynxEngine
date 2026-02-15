#pragma once

#include "LynxEngine/Events/Event.h"
#include "LynxEngine/Input/Keycodes.h"

namespace Lynx
{
	class KeyPressedEvent : public Event
	{
		public:
			DECL_EVENT_METHODS(KeyPressed)

			KeyPressedEvent(Keycode key) : key(key) {}
			Keycode getKey() const { return key; }

		private:
			Keycode key;
	};

	class KeyReleasedEvent : public Event
	{
		public:
			DECL_EVENT_METHODS(KeyReleased)

			KeyReleasedEvent(Keycode key) : key(key) {}
			Keycode getKey() const { return key; }

		private:
			Keycode key;
	};
}
