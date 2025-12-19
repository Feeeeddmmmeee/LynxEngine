cmake_minimum_required(VERSION 3.10)

project(LynxExampleGame)

# LSP support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(LynxEngine)
add_subdirectory(Game)
