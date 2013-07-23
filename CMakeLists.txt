cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)

project(libtrack CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(library_sources

    track_model.cc
    track_model.h
    track_io.cc
    track_io.h
)

add_subdirectory(tinyxml2 EXCLUDE_FROM_ALL)
include_directories(tinyxml2)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Os -Wall -Wextra -pedantic")

add_library(track STATIC ${library_sources})
target_link_libraries(track tinyxml2static)
