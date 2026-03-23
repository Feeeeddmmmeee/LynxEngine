# Lynx Engine
A simple (mostly) 2D game engine/framework written in C++ with Vulkan 

## :sparkles: Features
- [x]  Layer system
- [x]  Macro based logging
- [x]  Event system
    - [x] Non blocking event queue
    - [x] Window events (WindowClose, WindowMove, WindowResize, WindowEnterFullscreen, WindowExitFullscreen, WindowEnterFocus, WindowExitFocus)
    - [x] Keyboard events (KeyPressed, KeyReleased, KeyRepeat)
        - [x] Custom keycodes (Compatible with SDL3)
    - [x] Mouse events (MouseButtonPressed, MouseButtonReleased, MouseScroll, MouseMove)
- [x] Timestep and Clock classes for framerate independent motion
- [ ] User input polling
    - [x] SDL implementation
    - [ ] GLFW implementation
- [ ]  Graphics
    - [x] Window abstraction
    - [x] SDL window implementation
    - [ ] GLFW window implementation
    - [x] Perspective camera
    - [x] Simple perspective camera controller with WASD movement + mouse rotation + scroll zoom (fov) + speed boost when holding shift
    - [ ] Orthographic camera
    - [ ] Rendering (Loosely based on my [Vulkan learning repo](https://github.com/Feeeeddmmmeee/VulkanTesting))
- [ ]  Resource management
- [ ]  ECS
- [ ]  Audio support

## :rocket: Getting started
```cpp
#include <LynxEngine.h>

class MyLayer : public Lynx::Layer
{
  public:
    virtual void onAttach() override
    {
      LYNX_INFO("Hello World");
    }
};

int main()
{
  auto app = Lynx::Application();
  app.pushLayer<MyLayer>();
  app.run();
}
```

## :computer: Compile time options
| Name | Function | Default|
| --- | --- | --- |
| LYNX_CLIENT_LOG_LEVEL | Sets the client log level | LYNX_LOG_LEVEL_DEBUG |
| LYNX_ENGINE_LOG_LEVEL | Sets the engine log level | LYNX_LOG_LEVEL_NONE |
| LYNX_DISABLE_CLIENT_ASSERTS | Disables client asserts if defined | Undefined |
| LYNX_DISABLE_ENGINE_ASSERTS | Disabled engine asserts | Undefined |
| LYNX_DISABLE_ASSERTS | Defines the engine and client disable asserts macros | Undefined |
| LYNX_DISABLE_VULKAN_VALIDATION_LAYERS | Disables Vulkan validation layers | Undefined |

## :package: Dependencies
| Library | Use |
| --- | --- |
| Vulkan | Graphics API |
| SDL3 | Window creation, input |
| LunarG's Vulkan SDK | Provides Vulkan validation layers and a compiler for the slang shading language (sort of optional) |
| spdlog | Logging |
| glm | Math library |
| stb_image | Single header image loading library |
| tinyobjloader | Single header .obj file loader |

<br>

<p align="center">
    <img src="https://github.com/catppuccin/catppuccin/blob/main/assets/footers/gray0_ctp_on_line.png?raw=true">
</p>
