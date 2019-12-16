cmake_minimum_required(VERSION 3.15)
project(project)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lpthread -lX11")

set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics system window REQUIRED)
add_executable(project main.cpp renderer.cpp renderer.h snake.cpp snake.h utility.cpp utility.h
       libs/rectangularBoundaryCollision.hpp wallBuilder.cpp wallBuilder.h)
target_link_libraries(project sfml-graphics sfml-system sfml-window)
