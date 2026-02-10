# Lynx Engine
A simple 2D C++ game engine
## :sparkles: Features
- [x]  Layer system
- [x]  Macro based logging
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
}
```

## :package: Dependencies
- spdlog
- glm


<br>

<p align="center">
    <img src="https://github.com/catppuccin/catppuccin/blob/main/assets/footers/gray0_ctp_on_line.png?raw=true">
</p>
