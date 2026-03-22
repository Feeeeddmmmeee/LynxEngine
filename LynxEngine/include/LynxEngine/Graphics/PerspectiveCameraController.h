#pragma once

#include "LynxEngine/Graphics/PerspectiveCamera.h"
#include "LynxEngine/Events/Event.h"

namespace Lynx
{
	class PerspectiveCameraController
	{
		public:
			PerspectiveCameraController(PerspectiveCameraSpec spec);

			void onUpdate();
			void onEvent(Event *event);
			Camera &getCamera() { return camera; }

		private:
			PerspectiveCamera camera;

			float zoomSpeed = 0.0005f;
			float movementSpeed = 0.0005f;
			float mouseSpeed = 0.1f;
	};
}
