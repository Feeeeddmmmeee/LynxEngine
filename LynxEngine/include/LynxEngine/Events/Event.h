#pragma once

#define DECL_EVENT_METHODS(type) \
	static EventType getStaticType() { return EventType::type; } \
	virtual EventType getType() { return getStaticType(); }

namespace Lynx
{
	enum class EventType
	{
		None=0,

		WindowClose, WindowMove, WindowResize, WindowEnterFullscreen, 
		WindowExitFullscreen, WindowEnterFocus, WindowExitFocus,

		KeyPressed, KeyReleased, KeyRepeat,

		MouseMove, MouseScroll, MouseButtonPressed, MouseButtonReleased
	};

	class Event
	{
		public:
			virtual ~Event() = default;
			virtual EventType getType() = 0;

			bool handled = false;
	};
}

