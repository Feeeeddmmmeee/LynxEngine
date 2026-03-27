#include "LynxEngine/Graphics/Renderer/RenderCommand.h"

namespace Lynx
{
	static RendererAPI *rendererAPI = nullptr;

	RendererAPI *RenderCommand::getAPI()
	{
		if(!rendererAPI)
		{
			rendererAPI = RendererAPI::create();
		}

		return rendererAPI;
	}

	void RenderCommand::cleanup()
	{
		getAPI()->cleanup();
		delete rendererAPI;
		rendererAPI = nullptr;
	}
}
