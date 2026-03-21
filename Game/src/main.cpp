#include <LynxEngine.h>

#include <SDL3/SDL.h>
#include <glm/gtc/random.hpp>

// TEMPORARY !!!
extern SDL_Renderer *renderer;

class TestLayer : public Lynx::Layer
{
	public:
		TestLayer(Lynx::Application *app) : app(app) {}
		void onAttach() override
		{
			LYNX_DEBUG("Test layer attached...");
			SDL_SetRenderDrawColor(renderer, 0x0d, 0x2b, 0x45, 0);
		}

		bool callback(Lynx::MouseButtonEvent* e)
		{
			return 0;
		}

		void onEvent(Lynx::Event *event) override
		{
			Lynx::EventDispatcher d(event);
			d.dispatch<Lynx::KeyPressedEvent>([&](Lynx::KeyEvent *e){
					if(e->getKey() == Lynx::Keycode::Q) this->app->close(); 
					return 0;
				});
			d.dispatch<Lynx::KeyPressedEvent>([](){
					int r = glm::linearRand(0, 255);
					int g = glm::linearRand(0, 255);
					int b = glm::linearRand(0, 255);
					SDL_SetRenderDrawColor(renderer, r, g, b, 0);
					return true;
						});

			d.matchAny<Lynx::WindowEnterFocusEvent, Lynx::WindowExitFocusEvent>([](Lynx::Event*){
					int r = glm::linearRand(0, 255);
					int g = glm::linearRand(0, 255);
					int b = glm::linearRand(0, 255);
					SDL_SetRenderDrawColor(renderer, r, g, b, 0);
					return true;
					});

			d.matchAny<Lynx::MouseButtonPressedEvent, Lynx::MouseButtonReleasedEvent>([&](Lynx::MouseButtonEvent* e){return callback(e);});
		}
	private:
		Lynx::Application *app;
};

int main()
{
	Lynx::Application game = Lynx::Application();
	game.pushLayer<TestLayer>(&game);
	game.run();
}
