#include "Application.h"
#include "Layer.h"

class GameLayer : public Lynx::Layer
{
	public:
		std::string name;
		GameLayer(std::string n)
		{
			this->name=n;
		}
		void onAttach() override
		{
			LOG("Game layer attached... ("<<this->name<<")")
		}
};

class TestLayer : public Lynx::Layer
{
	public:
		void onDetach() override
		{
			LOG("Test layer detached...")
			this->getManager()->pushLayer<GameLayer>("TEST");
		}
};

int main()
{
	Lynx::Application game = Lynx::Application("Example", 640, 480);
	game.pushLayer<GameLayer>("First");
	game.pushLayer<TestLayer>();
	game.removeLayer<GameLayer>();
	game.removeLayer<TestLayer>();
	game.removeLayer<TestLayer>();
	game.run();
}
