cmake_minimum_required(VERSION 3.12)
project(PNG_MAPPER)

set(DEPS
        png-lite/pnglite.h
        png-lite/pnglite.cpp)

set(SOURCES
        png-mapper.cpp)

add_executable(png-mapper ${SOURCES})

target_compile_features(png-mapper PUBLIC cxx_std_17)
