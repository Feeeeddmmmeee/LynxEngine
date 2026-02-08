#include "Application.h"
#include "Layer.h"

class GameLayer : public Lynx::Layer
{
	void update() override
	{
		auto l = this->getManager()->getLayer<GameLayer>();
		l->queueTransition<Lynx::Layer>();
	}

	void render() override
	{
	}
};

int main()
{
	Lynx::Application game = Lynx::Application("Example", 640, 480);
	game.pushLayer<GameLayer>();
	game.run();
}
