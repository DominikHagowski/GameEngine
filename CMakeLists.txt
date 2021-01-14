cmake_minimum_required(VERSION 3.6)

project(Engine VERSION 0.0 LANGUAGES CXX C)

add_library(Engine STATIC ${CMAKE_SOURCE_DIR}/GameEngine/src/SystemManager.cpp ${CMAKE_SOURCE_DIR}/GameEngine/src/Systems/GraphicsSystem.cpp ${CMAKE_SOURCE_DIR}/GameEngine/src/Systems/TestSystem.cpp ${CMAKE_SOURCE_DIR}/GameEngine/src/Systems/GraphicsSystem.h)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/GameEngine/glfw)
include_directories(${CMAKE_SOURCE_DIR}/glfw/include)
target_link_libraries(Engine glfw)

include_directories(${CMAKE_SOURCE_DIR}/GameEngine/glad/include)
target_sources(Engine PRIVATE ${CMAKE_SOURCE_DIR}/GameEngine/glad/src/glad.c)

target_include_directories(Engine PUBLIC ${CMAKE_SOURCE_DIR}/GameEngine/include)
