# Lynx Engine
A simple 2D C++ game engine
## :sparkles: Features
- [x]  Layer system
- [x]  Macro based logging
- [ ]  Event system
    - [x] General event implementation
    - [ ] Window events
    - [ ] Keyboard events
    - [ ] Mouse events
- [ ]  ECS
- [ ]  Rendering
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
- spdlog
- glm


<br>

<p align="center">
    <img src="https://github.com/catppuccin/catppuccin/blob/main/assets/footers/gray0_ctp_on_line.png?raw=true">
</p>
