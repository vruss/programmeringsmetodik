cmake_minimum_required(VERSION 3.15)
project(project)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread -lX11")

set(SFML_DIR "libs/SFML-2.5.1/lib/cmake/SFML")

find_package(SFML COMPONENTS graphics  REQUIRED)
add_executable(project main.cpp)
target_link_libraries(project sfml-graphics )
