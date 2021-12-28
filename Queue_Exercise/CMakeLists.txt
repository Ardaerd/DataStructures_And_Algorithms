cmake_minimum_required(VERSION 3.20)
project(Queue_Exercise)

set(CMAKE_CXX_STANDARD 14)

add_executable(Queue_Exercise main.cpp Node.cpp Node.h MyCircularQueue.cpp MyCircularQueue.h)
