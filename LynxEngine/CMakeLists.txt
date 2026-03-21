cmake_minimum_required(VERSION 3.10)

project(LynxEngine)
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)

# LSP support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE ENGINE_CORE_SRC src/LynxEngine/*.cpp)
add_library(${PROJECT_NAME} STATIC ${ENGINE_CORE_SRC})

target_precompile_headers(${PROJECT_NAME}
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include/LynxPch.h
)

target_include_directories(${PROJECT_NAME} 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/
)

target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog glm::glm)

set(LYNX_WINDOW_BACKEND "SDL" CACHE STRING "Choose the window creation library (SDL)")
message(STATUS "Using window backend: ${LYNX_WINDOW_BACKEND}")
if(LYNX_WINDOW_BACKEND STREQUAL "SDL")
	find_package(SDL3 REQUIRED)
	file(GLOB_RECURSE SDL_SRC src/Platform/SDL/*.cpp)
	target_sources(${PROJECT_NAME} PRIVATE ${SDL_SRC})
	target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)

else()
	message(FATAL_ERROR "Unknown LYNX_WINDOW_BACKEND: '${LYNX_WINDOW_BACKEND}'. Must be one of: SDL")

endif()

set(LYNX_GRAPHICS_API "Vulkan" CACHE STRING "Choose the graphics API (Vulkan)")
message(STATUS "Using graphics API: ${LYNX_GRAPHICS_API}")
if(LYNX_WINDOW_BACKEND STREQUAL "SDL")
	find_package(Vulkan REQUIRED)
	file(GLOB_RECURSE VULKAN_SRC src/Platform/Vulkan/*.cpp)
	target_sources(${PROJECT_NAME} PRIVATE ${VULKAN_SRC})
	target_link_libraries(${PROJECT_NAME} PRIVATE Vulkan::Vulkan)

else()
	message(FATAL_ERROR "Unknown LYNX_GRAPHICS_API: '${LYNX_GRAPHICS_API}'. Must be one of: Vulkan")

endif()
