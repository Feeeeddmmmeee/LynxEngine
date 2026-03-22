#include "LynxEngine/Graphics/PerspectiveCameraController.h"
#include "LynxEngine/Events/EventDispatcher.h"
#include "LynxEngine/Events/MouseEvents.h"
#include "LynxEngine/Events/WindowEvents.h"
#include "LynxEngine/Input/InputManager.h"
#include "LynxEngine/Logging.h"

namespace Lynx
{
	PerspectiveCameraController::PerspectiveCameraController(PerspectiveCameraSpec spec)
		: camera(spec)
	{
	}

	void PerspectiveCameraController::onUpdate()
	{
		if(InputManager::isKeyPressed(Keycode::W))
		{
			camera.setPosition(camera.getPosition() + camera.getFront() * movementSpeed);
		}
		if(InputManager::isKeyPressed(Keycode::S))
		{
			camera.setPosition(camera.getPosition() - camera.getFront() * movementSpeed);
		}
		if(InputManager::isKeyPressed(Keycode::D))
		{
			camera.setPosition(camera.getPosition() + camera.getRight() * movementSpeed);
		}
		if(InputManager::isKeyPressed(Keycode::A))
		{
			camera.setPosition(camera.getPosition() - camera.getRight() * movementSpeed);
		}
		if(InputManager::isKeyPressed(Keycode::SPACE))
		{
			camera.setPosition(camera.getPosition() + camera.getUp() * movementSpeed);
		}
		if(InputManager::isKeyPressed(Keycode::LCTRL))
		{
			camera.setPosition(camera.getPosition() - camera.getUp() * movementSpeed);
		}
	}

	void PerspectiveCameraController::onEvent(Event *event)
	{
		EventDispatcher dispatcher(event);

		dispatcher.dispatch<MouseMoveEvent>([this](MouseMoveEvent *e){
				auto delta = e->getDelta() * mouseSpeed;
				auto newRot = camera.getRotation();

				newRot.y -= delta.x;
				newRot.x -= delta.y;

				this->camera.setRotation(newRot);
				return 0;
			});

		dispatcher.dispatch<MouseScrollEvent>([this](MouseScrollEvent *e){
				float fov = this->camera.getFov();
				fov += e->getDeltaY() * zoomSpeed;
				return 0;
			});

		dispatcher.dispatch<WindowResizeEvent>([this](WindowResizeEvent *e){
				this->camera.setDimensions({e->getWidth(), e->getHeight()});
				return 0;
			});
	}
}
