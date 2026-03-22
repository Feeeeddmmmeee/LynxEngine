#pragma once

#include "LynxEngine/Graphics/PerspectiveCamera.h"
#include "LynxEngine/Events/Event.h"

namespace Lynx
{
	class PerspectiveCameraController
	{
		public:
			PerspectiveCameraController(const PerspectiveCameraSpec &spec = PerspectiveCameraSpec());

			void onUpdate();
			void onEvent(Event *event);
			Camera &getCamera() { return camera; }

		private:
			PerspectiveCamera camera;

			float zoomSpeed = 1.0f;
			float movementSpeed = 0.0007f;
			float mouseSpeed = 0.1f;
	};
}
