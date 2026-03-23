#pragma once

#include "LynxEngine/Graphics/PerspectiveCamera.h"
#include "LynxEngine/Events/Event.h"
#include "LynxEngine/Time.h"

namespace Lynx
{
	class PerspectiveCameraController
	{
		public:
			PerspectiveCameraController(const PerspectiveCameraSpec &spec = PerspectiveCameraSpec());

			void onUpdate(Timestep dt);
			void onEvent(Event *event);
			Camera &getCamera() { return camera; }

		private:
			PerspectiveCamera camera;

			float zoomSpeed = 1.0f;
			float movementSpeed = 1.0f;
			float shiftMult = 3.0f;
			float mouseSpeed = 0.1f;
	};
}
