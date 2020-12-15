cmake_minimum_required(VERSION 3.6)

project(NEA VERSION 0.0 LANGUAGES CXX C)

add_executable(RocketSim "src/Main.cpp" "src/SystemManager.cpp" "src/Systems/GraphicsSystem.cpp" "src/Systems/TestSystem.cpp")

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT RocketSim)