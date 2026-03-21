#include "LynxEngine/Graphics/PerspectiveCamera.h"

namespace Lynx
{
	PerspectiveCamera::PerspectiveCamera(const PerspectiveCameraSpec &spec)
		: spec(spec)
	{
		recalculateProjectionMatrix();
		recalculateViewMatrix();
	}

	void PerspectiveCamera::setPosition(const glm::vec3 &pos)
	{
		spec.pos = pos;
		recalculateViewMatrix();
	}

	void PerspectiveCamera::setRotation(const glm::vec2 &pos)
	{
		spec.pitch = pos.x;
		spec.pitch = glm::clamp(spec.pitch, -89.0f, 89.0f);

		spec.yaw = pos.y;

		recalculateViewMatrix();
	}

	void PerspectiveCamera::recalculateViewMatrix()
	{
		recalculateBasis();
		viewMatrix = glm::lookAt(spec.pos, spec.pos + front, up);
	}

	void PerspectiveCamera::recalculateProjectionMatrix()
	{
		float aspectRatio = spec.width/spec.height;
		projectionMatrix = glm::perspective(
				glm::radians(spec.fov),
				aspectRatio,
				spec.near,
				spec.far
			);

		// otherwise it would be upside down
		projectionMatrix[1][1] *= -1;
	}

	void PerspectiveCamera::recalculateBasis()
	{
		front.x = cos(glm::radians(spec.pitch)) * cos(glm::radians(spec.yaw));
		front.y = cos(glm::radians(spec.pitch)) * sin(glm::radians(spec.yaw));
		front.z = sin(glm::radians(spec.pitch));
		front = glm::normalize(front);

		right = glm::normalize(glm::cross(front, Vec3::UP));
		up    = glm::normalize(glm::cross(right, front));
	}
}
