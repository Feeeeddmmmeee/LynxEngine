#include <LynxEngine.h>

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
		}
};

class TestLayer : public Lynx::Layer
{
	public:
		void onAttach() override
		{
			LYNX_DEBUG("Test layer attached...");
		}
		void onDetach() override
		{
			LYNX_DEBUG("Test layer detached...");
		}
		void onEvent(Lynx::Event *event) override
		{
			LYNX_WARN("Event handled by Test, {}", event->handled);
			event->handled = 1;
		}
};

int main()
{
	Lynx::Application game = Lynx::Application("Example", 640, 480);
	game.pushLayer<NamedLayer>("First");
	game.pushLayer<TestLayer>();
	game.removeLayer<NamedLayer>();
	game.swapLayer<TestLayer, NamedLayer>("Second");
	game.swapLayer<TestLayer, NamedLayer>();
	game.pushLayer<TestLayer>();
	game.run();
}
