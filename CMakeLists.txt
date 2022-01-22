cmake_minimum_required(VERSION 3.17)
project(TetrisITis)

set(CMAKE_CXX_STANDARD 14)

add_executable(TetrisITis main.cpp GameEngine.cpp GameEngine.h DrawableHUD.cpp DrawableHUD.h drawableTetromino.cpp drawableTetromino.h EventHandler.cpp EventHandler.h shapeStruct.h Vars.h)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(/usr/local/include)

find_package(SFML 2.5 COMPONENTS system window graphics network audio REQUIRED)
include_directories(${SFML_INCLUDE_DIRS})
target_link_libraries(TetrisITis sfml-system sfml-window sfml-graphics sfml-audio sfml-network)