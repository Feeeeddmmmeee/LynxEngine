# Lynx Engine
A simple 2D C++ game engine
## :sparkles: Features
- [x]  Layer system
- [x]  Macro based logging
- [x]  Event system
    - [x] Non blocking event queue
    - [x] Window events (WindowClose, WindowMove, WindowResize, WindowEnterFullscreen, WindowExitFullscreen, WindowEnterFocus, WindowExitFocus)
    - [x] Keyboard events (KeyPressed, KeyReleased, KeyRepeat)
        - [x] Custom keycodes
    - [x] Mouse events (MouseButtonPressed, MouseButtonReleased, MouseScroll, MouseMove)
- [x] User input polling
    - [x] SDL implementation
- [ ]  Graphics
    - [x] Window abstraction
    - [x] SDL window implementation
    - [ ] Rendering
- [ ]  ECS
- [ ]  Resource management
- [ ]  Audio support

## :rocket: Getting started
```cpp
#include <LynxEngine.h>

class MyLayer : public Lynx::Layer
{
  public:
    void onAttach() override
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

## :package: Dependencies
| Library | Use |
| --- | --- |
|spdlog | Logging |
| SDL3 | Window creation, input + probably rendering (SDL_GPU) |
| glm (likely, not actually used yet) | Math |

<br>

<p align="center">
    <img src="https://github.com/catppuccin/catppuccin/blob/main/assets/footers/gray0_ctp_on_line.png?raw=true">
</p>
