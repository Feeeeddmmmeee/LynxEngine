#pragma once

#include <memory>
#include <utility>

namespace Lynx
{
	template<typename T>
	using Arc = std::shared_ptr<T>;

	template<typename T, typename ...Args>
	constexpr Arc<T> makeArc(Args&& ...args)
	{
		return std::make_shared<T>(std::forward(args)...);
	}
}
