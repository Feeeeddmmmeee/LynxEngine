#pragma once

#include "LynxEngine/Events/Event.h"

#include <functional>

namespace Lynx
{
	class EventDispatcher
	{
		public:
			EventDispatcher(Lynx::Event *e) : event(e) {}

			template<typename TEvent>
			void dispatch(std::function<bool(TEvent*)> callback)
			{
				if(this->event->getType() == TEvent::getStaticType())
				{
					this->event->handled = callback((TEvent*)this->event);
				}
			}

			template<typename... TEvents>
			void matchAny(std::function<bool()> callback)
			{
				(([&]{
					if(this->event->getType() == TEvents::getStaticType())
					{
						this->event->handled = callback();
						return true;
					}
				return false;
				}()) || ... );
			}

		private:
			Event *event;
	};
}
