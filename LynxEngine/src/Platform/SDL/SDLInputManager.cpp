#include "LynxEngine/Input/InputManager.h"

#include <SDL3/SDL_keyboard.h>
#include <SDL3/SDL_mouse.h>

namespace Lynx
{

	bool InputManager::isKeyPressed(Keycode key)
	{
		int scanCode = SDL_GetScancodeFromKey((int)key, NULL);
		return SDL_GetKeyboardState(nullptr)[scanCode];
	}

	bool InputManager::isMouseButtonPressed(Mousecode button)
	{
		return SDL_GetMouseState(nullptr,nullptr) & SDL_BUTTON_MASK((int)button);
	}

	std::pair<float,float> InputManager::getMousePosition()
	{
		std::pair<float, float> pos;
		SDL_GetMouseState(&pos.first, &pos.second);
		return pos;
	}

	float InputManager::getMouseX()
	{
		return getMousePosition().first;
	}

	float InputManager::getMouseY()
	{
		return getMousePosition().second;
	}
}
