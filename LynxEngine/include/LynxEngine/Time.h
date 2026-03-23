#pragma once

namespace Lynx
{
	class Timestep
	{
		public:
			Timestep(float time = 0) : time(time) {}

			operator float() const { return time; }
			float seconds() const { return time; }
			float milliseconds() const { return time*1000; }
			float fps() const { return 1/time; }
		private:
			float time;
	};

	class Clock
	{
		public:
			Clock()
				: last(std::chrono::steady_clock::now()) {}

			Timestep tick()
			{
				auto now = std::chrono::steady_clock::now();
				std::chrono::duration<float> delta = now - last;
				last = now;

				return Timestep(delta.count());
			}
		private:
			std::chrono::steady_clock::time_point last;
	};
}
