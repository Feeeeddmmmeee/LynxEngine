#include <LynxEngine.h>

#include <glm/gtc/random.hpp>

class TestLayer : public Lynx::Layer
{
	public:
		TestLayer(Lynx::Application *app) 
			: app(app) , cam({.width = 1080, .height =  720})
		{}

		void onAttach() override
		{
			LYNX_DEBUG("Test layer attached...");
		}

		void onUpdate() override
		{
			Lynx::Renderer::beginScene(cam);
			Lynx::Renderer::submit();
			Lynx::Renderer::endScene();
		}

		void onEvent(Lynx::Event *event) override
		{
			Lynx::EventDispatcher d(event);
			d.dispatch<Lynx::KeyPressedEvent>([&](Lynx::KeyEvent *e){
					if(e->getKey() == Lynx::Keycode::Q) this->app->close(); 
					return 0;
				});
		}
	private:
		Lynx::PerspectiveCamera cam;
		Lynx::Application *app;
};

int main()
{
	Lynx::Application game = Lynx::Application();
	game.pushLayer<TestLayer>(&game);
	game.run();
}
