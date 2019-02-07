cmake_minimum_required(VERSION 3.13)
project(fuzzyLogic)

set(CMAKE_CXX_STANDARD 14)

file(
        GLOB_RECURSE
        sources
        src/*
)

add_executable(fuzzyLogic ${sources})