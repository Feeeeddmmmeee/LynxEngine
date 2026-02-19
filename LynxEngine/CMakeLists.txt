cmake_minimum_required(VERSION 3.10)

project(LynxEngine)
find_package(spdlog REQUIRED)
find_package(glm REQUIRED)
find_package(SDL3 REQUIRED)

# LSP support
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_library(${PROJECT_NAME} STATIC ${SRC_FILES})

target_include_directories(${PROJECT_NAME} 
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include/
	PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/)

target_link_libraries(${PROJECT_NAME} PUBLIC spdlog::spdlog glm::glm)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
