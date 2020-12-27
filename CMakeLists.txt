cmake_minimum_required(VERSION 3.6)

project(NEA VERSION 0.0 LANGUAGES CXX C)

add_executable(RocketSim "src/Main.cpp" "src/SystemManager.cpp" "src/Systems/GraphicsSystem.cpp" "src/Systems/TestSystem.cpp" "src/Systems/GraphicsSystem.h")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT RocketSim)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(${CMAKE_SOURCE_DIR}/glfw)
include_directories(${CMAKE_SOURCE_DIR}/glfw/include)
target_link_libraries(RocketSim glfw)

include_directories(${CMAKE_SOURCE_DIR}/glad/include)
target_sources(RocketSim PRIVATE ${CMAKE_SOURCE_DIR}/glad/src/glad.c)
