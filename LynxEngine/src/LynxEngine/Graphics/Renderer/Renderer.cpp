#include "LynxEngine/Graphics/Renderer/Renderer.h"
#include "LynxEngine/Graphics/Renderer/RenderCommand.h"

namespace Lynx
{
	void Renderer::init(Window *window)
	{
		RenderCommand::init(window);
	}

	void Renderer::beginScene(Camera &camera)
	{
		RenderCommand::setCamera(camera);
	}

	void Renderer::submit()
	{
		RenderCommand::draw();
	}

	void Renderer::endScene()
	{
	}

	void Renderer::cleanup()
	{
	}
}
