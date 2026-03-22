#include <LynxEngine.h>

#include <glm/gtc/random.hpp>

class TestLayer : public Lynx::Layer
{
	public:
		TestLayer(Lynx::Application *app) 
			: app(app)
		{}

		void onAttach() override
		{
			LYNX_DEBUG("Test layer attached...");
		}

		void onUpdate() override
		{
			cam.onUpdate();

			Lynx::Renderer::beginScene(cam.getCamera());
			Lynx::Renderer::submit();
			Lynx::Renderer::endScene();
		}

		void onEvent(Lynx::Event *event) override
		{
			cam.onEvent(event);
			Lynx::EventDispatcher d(event);
			d.dispatch<Lynx::KeyPressedEvent>([&](Lynx::KeyEvent *e){
					if(e->getKey() == Lynx::Keycode::Q) this->app->close(); 
					return 0;
				});
		}
	private:
		Lynx::PerspectiveCameraController cam;
		Lynx::Application *app;
};

int main()
{
	Lynx::Application game = Lynx::Application({.showMouse = false});
	game.pushLayer<TestLayer>(&game);
	game.run();
}
