namespace Lynx
{
	class Event
	{
		public:
			virtual ~Event() = default;

			bool handled = false;
	};
}
