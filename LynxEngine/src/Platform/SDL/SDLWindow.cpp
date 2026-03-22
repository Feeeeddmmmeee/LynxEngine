#include "LynxEngine/Events/WindowEvents.h"
#include "LynxEngine/Events/KeyboardEvents.h"
#include "LynxEngine/Events/MouseEvents.h"
#include "LynxEngine/Logging.h"

#include "Platform/SDL/SDLWindow.h"

#include <SDL3/SDL.h>

#ifdef LYNX_VULKAN
#include <SDL3/SDL_vulkan.h>
#endif

namespace Lynx
{
	static bool initializedSDL = 0;

	Window *Window::create(const WindowSpec &spec)
	{
		return new SDLWindow(spec);
	}

	glm::vec2 SDLWindow::getFramebufferSize()
	{
		int w, h;
		SDL_GetWindowSizeInPixels(window, &w, &h);
		return glm::vec2{w,h};
	}

#ifdef LYNX_VULKAN
	const char* const* Window::getInstanceExtensions(uint32_t *count)
	{
		return SDL_Vulkan_GetInstanceExtensions(count);
	}

	void SDLWindow::createVulkanSurface(VkInstance instance, VkSurfaceKHR *surface)
	{
		LYNX_ENGINE_DEBUG("TROL");
		bool success = SDL_Vulkan_CreateSurface(this->window, instance, nullptr, surface);
		LYNX_ENGINE_ASSERT(success, "Failed to create Vulkan surface!");
	}
#endif

	glm::vec2 SDLWindow::getSize()
	{
		return glm::vec2(spec.width, spec.height);
	}

	void SDLWindow::update()
	{
		this->pollSDLEvents();
	}

	void SDLWindow::setEventCallback(std::function<void(Event*)> callback)
	{
		this->eventCallback = callback;
	}

	void SDLWindow::pollSDLEvents()
	{
		SDL_Event e;
		while(SDL_PollEvent(&e))
		{
			switch(e.type)
			{
				// WINDOW EVENTS
				case SDL_EVENT_QUIT:
					this->eventCallback(new WindowCloseEvent());
					break;
				case SDL_EVENT_WINDOW_RESIZED:
					this->eventCallback(new WindowResizeEvent(e.window.data1, e.window.data2));
					this->spec.width = e.window.data1;
					this->spec.height = e.window.data2;
					break;
				case SDL_EVENT_WINDOW_MOVED:
					this->eventCallback(new WindowMoveEvent(e.window.data1, e.window.data2));
					break;
				case SDL_EVENT_WINDOW_ENTER_FULLSCREEN:
					this->eventCallback(new WindowEnterFullscreenEvent());
					break;
				case SDL_EVENT_WINDOW_LEAVE_FULLSCREEN:
					this->eventCallback(new WindowExitFullscreenEvent());
					break;
				case SDL_EVENT_WINDOW_FOCUS_GAINED:
					this->eventCallback(new WindowEnterFocusEvent());
					break;
				case SDL_EVENT_WINDOW_FOCUS_LOST:
					this->eventCallback(new WindowExitFocusEvent());
					break;

				// KEYBOARD EVENTS
				case SDL_EVENT_KEY_DOWN:
					if(e.key.repeat)
						this->eventCallback(new KeyRepeatEvent((Keycode)e.key.key));
					else
						this->eventCallback(new KeyPressedEvent((Keycode)e.key.key));
					break;
				case SDL_EVENT_KEY_UP:
					this->eventCallback(new KeyReleasedEvent((Keycode)e.key.key));
					break;

				// MOUSE EVENTS
				case SDL_EVENT_MOUSE_MOTION:
					this->eventCallback(new MouseMoveEvent(e.motion.xrel, e.motion.yrel));
					break;
				case SDL_EVENT_MOUSE_WHEEL:
					this->eventCallback(new MouseScrollEvent(e.wheel.x, e.wheel.y));
					break;
				case SDL_EVENT_MOUSE_BUTTON_DOWN:
					this->eventCallback(new MouseButtonPressedEvent((Mousecode)e.button.button));
					break;
				case SDL_EVENT_MOUSE_BUTTON_UP:
					this->eventCallback(new MouseButtonReleasedEvent((Mousecode)e.button.button));
					break;
				default:
					break;
			}
		}
	}

	SDLWindow::SDLWindow(const WindowSpec &spec)
	{
		this->spec = spec;
		if(!initializedSDL)
		{
			SDL_SetLogPriorities(SDL_LOG_PRIORITY_VERBOSE);
			SDL_SetLogOutputFunction([](void*, int, SDL_LogPriority, const char* msg){
				LYNX_ENGINE_DEBUG(msg);
			}, 0);

			SDL_SetHint(SDL_HINT_APP_NAME, spec.name.c_str());


			LYNX_ENGINE_DEBUG("Initializing SDL...");
			bool SDLInit = SDL_Init(SDL_INIT_VIDEO);
			LYNX_ENGINE_ASSERT(SDLInit, "Failed to initialize SDL!");


#ifdef LYNX_VULKAN
			SDL_Vulkan_LoadLibrary(NULL);
#endif
			initializedSDL = 1;
		}

		unsigned long flags = 0;
		if(spec.fullscreen) flags |= SDL_WINDOW_FULLSCREEN;
		if(spec.resizable) flags |= SDL_WINDOW_RESIZABLE;

#ifdef LYNX_VULKAN
		flags |= SDL_WINDOW_VULKAN;
#endif

		LYNX_ENGINE_DEBUG("Creating SDL Window...");
		this->window = SDL_CreateWindow(spec.name.c_str(), spec.width, spec.height, flags);
		LYNX_ENGINE_ASSERT(this->window, "Failed to create SDL window!");

		if(!spec.showMouse)
		{
			SDL_SetWindowRelativeMouseMode(window, true);
			SDL_HideCursor();
		}
	}

	SDLWindow::~SDLWindow()
	{
		SDL_DestroyWindow(this->window);
	}
	
	void SDLWindow::setFullscreen(bool fullscreen)
	{
		SDL_SetWindowFullscreen(this->window, fullscreen);
	}

	void SDLWindow::setResizable(bool resizable)
	{
		SDL_SetWindowResizable(this->window, resizable);
	}

	void SDLWindow::setTitle(std::string title)
	{
		SDL_SetWindowTitle(this->window, title.c_str());
	}
}
