cmake_minimum_required(VERSION 3.17)
project(untitled)

set(CMAKE_CXX_STANDARD 14)
add_compile_options(-std=c++2a -Werror -Wsign-conversion)
#add_executable(Demo1.cpp Demo2.cpp)
add_executable(test1 StudentTest1.cpp doctest.h sources/Role.cpp sources/Role.hpp sources/Board.cpp sources/Board.hpp sources/City.hpp sources/Color.hpp sources/Player.cpp sources/Player.hpp )
add_executable(demo1 Demo1.cpp sources/Role.cpp sources/Role.hpp sources/Board.cpp sources/Board.hpp sources/City.hpp sources/Color.hpp sources/Player.cpp sources/Player.hpp )