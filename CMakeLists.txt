cmake_minimum_required(VERSION 3.9.2)
project(fuzzy)

set(CMAKE_CXX_STANDARD 14)

file(
        GLOB_RECURSE
        sources
        src/*
)

add_executable(fuzzy ${sources} src/fuzzy/Then/ThenMin.h src/fuzzy/Then/Then.h src/fuzzy/And/AndMult.h)
