#pragma once

#include "LynxEngine/Events/Event.h"

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

			template<typename TEvent>
			void dispatch(std::function<bool()> callback)
			{
				if(this->event->getType() == TEvent::getStaticType())
				{
					this->event->handled = callback();
				}
			}

			template<typename... TEvents, typename F>
			void matchAny(F callback)
			{
				(([&]{
					if(this->event->getType() == TEvents::getStaticType())
					{
						this->event->handled = callback((TEvents*)this->event);
						return true;
					}
				return false;
				}()) || ... );
			}

		private:
			Event *event;
	};
}
