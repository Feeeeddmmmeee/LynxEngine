#include <LynxEngine.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h>

// TEMPORARY !!!
extern SDL_Renderer *renderer;

class NamedLayer : public Lynx::Layer
{
	public:
		std::string name;
		NamedLayer(std::string n) : name(n) {}
		NamedLayer() : name("NamedLayer"){}
		void onAttach() override
		{
			LYNX_DEBUG("Named layer {} attached... ",this->name);
		}
		void onEvent(Lynx::Event *event) override
		{
			LYNX_WARN("Event handled by {}", this->name);
			Lynx::EventDispatcher d(event);
		}
};

class TestLayer : public Lynx::Layer
{
	public:
		void onAttach() override
		{
			LYNX_DEBUG("Test layer attached...");
			SDL_SetRenderDrawColor(renderer, 0x0d, 0x2b, 0x45, 0);
		}
		void onDetach() override
		{
			LYNX_DEBUG("Test layer detached...");
		}
		void onEvent(Lynx::Event *event) override
		{
			LYNX_WARN("Event handled by Test, {}", event->handled);
		}
};

int main()
{
	Lynx::WindowSpec spec;
	Lynx::Application game = Lynx::Application(spec);
	game.pushLayer<TestLayer>();
	game.pushLayer<NamedLayer>();
	game.run();
}
