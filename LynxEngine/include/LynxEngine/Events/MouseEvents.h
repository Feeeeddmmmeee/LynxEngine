#pragma once

#include <utility>

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

	class MouseScrollEvent : public Event
	{
		public:
			DECL_EVENT_METHODS(MouseScroll)

			MouseScrollEvent(float dx, float dy) : dx(dx), dy(dy) {}
			std::pair<float, float> getDelta() const { return std::make_pair(dx, dy); }
			float getDeltaX() const { return dx; }
			float getDeltaY() const { return dy; }

		private:
			float dx, dy;
	};

	class MouseMoveEvent : public Event
	{
		public:
			DECL_EVENT_METHODS(MouseMove)

			MouseMoveEvent(float x, float y) : x(x), y(y) {}
			std::pair<float, float> getPos() const { return std::make_pair(x, y); }
			float getX() const { return x; }
			float getY() const { return y; }

		private:
			float x, y;
	};
}
