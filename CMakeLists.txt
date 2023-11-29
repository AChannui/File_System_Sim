cmake_minimum_required(VERSION 3.24)
project(CS4348OS_Project3)

set(CMAKE_CXX_STANDARD 11)

add_executable(CS4348OS_Project3 main.cpp FileSystem.h Disk.h Block.h
        UserInterface.h
        ContiguousSystem.h
        ChainedSystem.h
        IndexSystem.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sample1 DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
