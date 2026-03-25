#pragma once

namespace Lynx
{
	class Timestep
	{
		public:
			Timestep(float time = 0) : time(time) {}

			inline operator float() const { return time; }
			inline float seconds() const { return time; }
			inline float milliseconds() const { return time*1000; }
			inline float fps() const { return 1/time; }
		private:
			float time;
	};

	class Clock
	{
		public:
			Clock()
				: last(std::chrono::steady_clock::now()) {}

			inline Timestep tick()
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
