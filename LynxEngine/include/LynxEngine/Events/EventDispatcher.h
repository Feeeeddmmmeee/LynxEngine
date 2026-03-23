#pragma once

#include "LynxEngine/Events/Event.h"

namespace Lynx
{
	class EventDispatcher
	{
		public:
			EventDispatcher(Lynx::Event *e) : event(e) {}

			template<typename TEvent, typename Func>
			void dispatch(Func&& callback)
			{
				if (this->event->getType() == TEvent::getStaticType())
				{
					if constexpr (std::is_invocable_v<Func, TEvent*>)
					{
						if constexpr (std::is_convertible_v<std::invoke_result_t<Func, TEvent*>, bool>)
							this->event->handled = callback((TEvent*)this->event);
						else
							callback((TEvent*)this->event);
					}
					else if constexpr (std::is_invocable_v<Func>)
					{
						if constexpr (std::is_convertible_v<std::invoke_result_t<Func>, bool>)
							this->event->handled = callback();
						else
							callback();
					}
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
