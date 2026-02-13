#include <LynxEngine.h>
#include <LynxEngine/Events/EventDispatcher.h>

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
	Lynx::Application game = Lynx::Application("Example", 640, 480);
	game.pushLayer<TestLayer>();
	game.pushLayer<NamedLayer>();
	game.run();
}
