#pragma once

#include <glm/glm.hpp>

namespace Lynx
{
	template<typename T>
	using Arc = std::shared_ptr<T>;

	template<typename T, typename ...Args>
	constexpr Arc<T> makeArc(Args&& ...args)
	{
		return std::make_shared<T>(std::forward(args)...);
	}

	class Vec3
	{
		public:
			static constexpr glm::vec3 UP = {0, 0, 1};
			static constexpr glm::vec3 DOWN = {0, 0, -1};
			static constexpr glm::vec3 FRONT = {0, 1, 0};
			static constexpr glm::vec3 BACK = {0, -1, 0};
			static constexpr glm::vec3 LEFT = {1, 0, 0};
			static constexpr glm::vec3 RIGHT = {-1, 0, 0};
	};
}
