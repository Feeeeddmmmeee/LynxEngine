cmake_minimum_required(VERSION 3.10)

project(LynxExampleGame)

# LSP support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# All log messages
add_compile_definitions(LYNX_LOG_LEVEL=0)

add_subdirectory(LynxEngine)
add_subdirectory(Game)
