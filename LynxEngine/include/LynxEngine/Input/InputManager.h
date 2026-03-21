#pragma once

#include "LynxEngine/Input/Mousecodes.h"
#include "LynxEngine/Input/Keycodes.h"

namespace Lynx
{
	class InputManager
	{
		public:
			static bool isKeyPressed(Keycode key);
			static bool isMouseButtonPressed(Mousecode button);
			static glm::vec2 getMousePosition();
			static float getMouseX();
			static float getMouseY();
	};
};
