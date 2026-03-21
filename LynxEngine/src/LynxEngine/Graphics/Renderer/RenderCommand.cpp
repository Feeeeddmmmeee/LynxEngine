#include "LynxEngine/Graphics/Renderer/RenderCommand.h"

namespace Lynx
{
	Scope<RendererAPI> RenderCommand::rendererAPI = makeScope<RendererAPI>(RendererAPI::create());
}
