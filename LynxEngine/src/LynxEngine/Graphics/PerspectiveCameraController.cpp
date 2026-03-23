#include "LynxEngine/Graphics/PerspectiveCameraController.h"
#include "LynxEngine/Events/EventDispatcher.h"
#include "LynxEngine/Events/MouseEvents.h"
#include "LynxEngine/Events/WindowEvents.h"
#include "LynxEngine/Input/InputManager.h"

namespace Lynx
{
	PerspectiveCameraController::PerspectiveCameraController(const PerspectiveCameraSpec &spec)
		: camera(spec)
	{
	}

	void PerspectiveCameraController::onUpdate(Timestep dt)
	{
		float mult = movementSpeed * dt;
		if(InputManager::isKeyPressed(Keycode::LSHIFT))
			mult *= shiftMult;

		if(InputManager::isKeyPressed(Keycode::W))
		{
			camera.setPosition(camera.getPosition() + camera.getFront() * mult);
		}
		else if(InputManager::isKeyPressed(Keycode::S))
		{
			camera.setPosition(camera.getPosition() - camera.getFront() * mult);
		}

		if(InputManager::isKeyPressed(Keycode::D))
		{
			camera.setPosition(camera.getPosition() + camera.getRight() * mult);
		}
		else if(InputManager::isKeyPressed(Keycode::A))
		{
			camera.setPosition(camera.getPosition() - camera.getRight() * mult);
		}

		if(InputManager::isKeyPressed(Keycode::SPACE))
		{
			camera.setPosition(camera.getPosition() + camera.getUp() * mult);
		}
		else if(InputManager::isKeyPressed(Keycode::LCTRL))
		{
			camera.setPosition(camera.getPosition() - camera.getUp() * mult);
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
			});

		dispatcher.dispatch<MouseScrollEvent>([this](MouseScrollEvent *e){
				float fov = this->camera.getFov();
				fov -= e->getDeltaY() * zoomSpeed;
				this->camera.setFov(fov);
			});

		dispatcher.dispatch<WindowResizeEvent>([this](WindowResizeEvent *e){
				this->camera.setDimensions({e->getWidth(), e->getHeight()});
			});
	}
}
