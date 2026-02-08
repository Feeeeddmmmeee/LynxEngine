#include "Application.h"
#include "Layer.h"

class GameLayer : public Lynx::Layer
{
	public:
		void onAttach() override
		{
			LOG("Game layer attached...")
		}
};

class TestLayer : public Lynx::Layer
{
	public:
		void onDetach() override
		{
			LOG("Test layer detached...")
			this->getManager()->pushLayer<GameLayer>();
		}
};

int main()
{
	Lynx::Application game = Lynx::Application("Example", 640, 480);
	game.pushLayer<GameLayer>();
	game.pushLayer<TestLayer>();
	game.removeLayer<TestLayer>();
	game.removeLayer<TestLayer>();
	game.run();
}
