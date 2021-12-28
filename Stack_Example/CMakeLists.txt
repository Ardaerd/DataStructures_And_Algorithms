cmake_minimum_required(VERSION 3.20)
project(Stack_Example)

set(CMAKE_CXX_STANDARD 14)

add_executable(Stack_Example main.cpp Node.h Node.cpp LinkedList.cpp LinkedList.h)
