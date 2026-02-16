#pragma once

#include "LynxEngine/Events/Event.h"
#include "LynxEngine/Input/Mousecodes.h"

namespace Lynx
{
	class MouseButtonEvent : public Event
	{
		public:
			MouseButtonEvent(Mousecode button) : button(button) {}
			Mousecode getButton() const { return button; }

		private:
			Mousecode button;
	};

	class MouseButtonPressedEvent : public MouseButtonEvent
	{
		public:
			DECL_EVENT_METHODS(MouseButtonPressed)

			MouseButtonPressedEvent(Mousecode button) : MouseButtonEvent(button) {}

	};

	class MouseButtonReleasedEvent : public MouseButtonEvent
	{
		public:
			DECL_EVENT_METHODS(MouseButtonReleased)

			MouseButtonReleasedEvent(Mousecode button) : MouseButtonEvent(button) {}
	};
}
