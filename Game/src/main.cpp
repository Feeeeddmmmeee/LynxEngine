#include <LynxEngine.h>

class TestLayer : public Lynx::Layer
{
	public:
		TestLayer(Lynx::Application *app) 
			: app(app)
		{}

		void onUpdate(Lynx::Timestep dt) override
		{
			cam.onUpdate(dt);

			Lynx::Renderer::beginScene(cam.getCamera());
			Lynx::Renderer::submit();
			Lynx::Renderer::endScene();
		}

		void onEvent(Lynx::Event *event) override
		{
			cam.onEvent(event);
			Lynx::EventDispatcher d(event);
			d.dispatch<Lynx::KeyPressedEvent>([&](Lynx::KeyEvent *e){
					if(e->getKey() == Lynx::Keycode::Q) 
						this->app->close(); 
				});
		}
	private:
		Lynx::PerspectiveCameraController cam;
		Lynx::Application *app;
};

int main()
{
	Lynx::Arc<Lynx::Window> window = Lynx::Window::create({.showMouse = false});
	Lynx::Application game = Lynx::Application(window);

	Lynx::Renderer::init(window.get());
	game.pushLayer<TestLayer>(&game);
	game.run();

	Lynx::Renderer::cleanup();
}
