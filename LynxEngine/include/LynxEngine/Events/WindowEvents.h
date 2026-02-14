#pragma once

#include "LynxEngine/Events/Event.h"

namespace Lynx
{
	class WindowCloseEvent : public Event
	{
		public:
			DECL_EVENT_METHODS(WindowClose)
	};

	class WindowResizeEvent : public Event
	{
		public:
			DECL_EVENT_METHODS(WindowResize)

			WindowResizeEvent(int x, int y) : width(x), height(y) {}
			int getWidth() const { return width; }
			int getHeight() const { return height; }

		private:
			int width, height;
	};

	class WindowMoveEvent : public Event
	{
		public:
			DECL_EVENT_METHODS(WindowMove)

			WindowMoveEvent(int newX, int newY) : x(newX), y(newY) {}
			int getX() const { return x; }
			int getY() const { return y; }

		private:
			int x, y;
	};

}
