cmake_minimum_required(VERSION 2.8.9 FATAL_ERROR)

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

include(GenerateExportHeader)
add_library(track STATIC ${library_sources})
generate_export_header(track)
add_compiler_export_flags()