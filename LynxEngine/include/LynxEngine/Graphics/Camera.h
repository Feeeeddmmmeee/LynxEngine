#pragma once

namespace Lynx
{

	class Camera
	{
		public:
			virtual ~Camera() = default;

			virtual const glm::mat4 &getViewMatrix() const = 0;
			virtual const glm::mat4 &getProjectionMatrix() const = 0;
	};
}
