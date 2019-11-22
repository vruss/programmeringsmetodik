cmake_minimum_required(VERSION 3.15)
project(lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab2 main.cpp shape.cpp shape.h circle.cpp circle.h cylinder.cpp cylinder.h rectangle.cpp rectangle.h parallelepiped.cpp parallelepiped.h rounded_rectangle.cpp rounded_rectangle.h)

add_subdirectory(tests)