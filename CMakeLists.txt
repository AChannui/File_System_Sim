cmake_minimum_required(VERSION 3.24)
project(CS4348OS_Project3)

set(CMAKE_CXX_STANDARD 11)

add_executable(CS4348OS_Project3 main.cpp FileSystem.cpp FileSystem.h Disk.cpp Disk.h Block.h
        UserInterface.cpp
        UserInterface.h)
