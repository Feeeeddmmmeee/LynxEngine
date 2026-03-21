#pragma once

#include "LynxEngine/Core.h"

#define GLM_ENABLE_EXPERIMENTAL
#define GLM_FORCE_DEFAULT_ALIGNED_GENTYPES
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Lynx
{
	struct PerspectiveCameraSpec
	{
		float width;
		float height;
		float fov = 45.0f;
		glm::vec3 pos = {0,0,0};
		float near = .01f;
		float far = 100.0f;
		float pitch = 0;
		float yaw = 0;
	};

	class PerspectiveCamera
	{
		public:
			PerspectiveCamera(const PerspectiveCameraSpec &spec);

			inline const glm::vec3 &getPosition() const { return spec.pos; }
			void setPosition(const glm::vec3 &pos);

			inline glm::vec2 getRotation() const { return glm::vec2(spec.pitch, spec.yaw); }
			void setRotation(const glm::vec2 &rotation);

			inline const glm::mat4 &getViewMatrix() const { return viewMatrix; }
			inline const glm::mat4 &getProjectionMatrix() const { return projectionMatrix; }

			inline const glm::vec3& getFront() const { return front; }
			inline const glm::vec3& getRight() const { return right; }
			inline const glm::vec3& getUp() const { return up; }

		private:
			void recalculateViewMatrix();
			void recalculateProjectionMatrix();
			void recalculateBasis();

			PerspectiveCameraSpec spec;

			glm::mat4 projectionMatrix;
			glm::mat4 viewMatrix;

			glm::vec3 front = Vec3::FRONT;
			glm::vec3 right = Vec3::RIGHT;
			glm::vec3 up = Vec3::UP;
	};
}
