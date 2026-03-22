#pragma once

namespace Lynx
{
	template<typename T>
	using Arc = std::shared_ptr<T>;

	template<typename T, typename ...Args>
	constexpr Arc<T> makeArc(Args&& ...args)
	{
		return std::make_shared<T>(std::forward(args)...);
	}

	template<typename T>
	constexpr Arc<T> makeArc(T* ptr)
	{
		return std::shared_ptr<T>(ptr);
	}

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ...Args>
	constexpr Scope<T> makeScope(Args&& ...args)
	{
		return std::make_unique<T>(std::forward(args)...);
	}

	template<typename T>
	constexpr Scope<T> makeScope(T* ptr)
	{
		return std::unique_ptr<T>(ptr);
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
