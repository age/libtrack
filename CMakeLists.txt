cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)

project(libtrack CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(library_sources

    track_model.cc
    track_model.h
    track_io.cc
    track_io.h
    tinyxml2.h
    tinyxml2.cpp
)

# TODO: add Clang, MSVC compile flags?
if (CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Os -Wall -Wextra -pedantic")
endif()


include(GenerateExportHeader)
add_library(track STATIC ${library_sources})
generate_export_header(track)
add_compiler_export_flags()
