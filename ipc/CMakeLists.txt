cmake_minimum_required(VERSION 3.10)
project(sharememory)

add_executable(writer writer.cpp shminterface.hpp)
add_executable(reader writer.cpp shminterface.hpp)