#pragma once

#include <utility>

#include "LynxEngine/Input/Mousecodes.h"
#include "LynxEngine/Input/Keycodes.h"

namespace Lynx
{
	class InputManager
	{
		public:
			static bool isKeyPressed(Keycode key);
			static bool isMouseButtonPressed(Mousecode button);
			static std::pair<float,float> getMousePosition();
			static float getMouseX();
			static float getMouseY();
	};
};
