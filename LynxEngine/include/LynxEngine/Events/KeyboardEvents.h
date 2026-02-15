#pragma once

#include "LynxEngine/Events/Event.h"
#include "LynxEngine/Input/Keycodes.h"

namespace Lynx
{
	class KeyEvent : public Event 
	{
		public:
			KeyEvent(Keycode key) : key(key) {}
			Keycode getKey() const { return key; }
		private:
			Keycode key;
	};

	class KeyPressedEvent : public KeyEvent
	{
		public:
			DECL_EVENT_METHODS(KeyPressed)

			KeyPressedEvent(Keycode key) : KeyEvent(key) {}
	};

	class KeyReleasedEvent : public KeyEvent
	{
		public:
			DECL_EVENT_METHODS(KeyReleased)

			KeyReleasedEvent(Keycode key) : KeyEvent(key) {}
	};
}
