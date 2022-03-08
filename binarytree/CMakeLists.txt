cmake_minimum_required(VERSION 3.19)
project(BinaryTree)

set(CMAKE_CXX_STANDARD 20)

add_executable(demo Demo.cpp sources/BinaryTree.hpp)
add_executable(test Test.cpp  sources/BinaryTree.hpp)
#add_executable(test1 StudentTest1.cpp sources/BinaryTree.hpp)
#add_executable(test2 StudentTest2.cpp sources/BinaryTree.hpp)
add_executable(test3 StudentTest3.cpp  sources/BinaryTree.hpp)
