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

include(CheckCXXCompilerFlag)

# TODO: add Clang, MSVC compile flags?
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Os -Wall -Wextra -pedantic")
  CHECK_CXX_COMPILER_FLAG("-std=c++11" STDCPP11_SUPPORTED)
  if(STDCPP11_SUPPORTED)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  else()
    CHECK_CXX_COMPILER_FLAG("-std=c++0x" STDCPP0X_SUPPORTED)
    if(STDCPP0X_SUPPORTED)
      set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    else()
      message(FATAL_ERROR "Compiler doesn't appear to support C++11 or at least C++0x")
    endif()
  endif()
endif()

include_directories(${CMAKE_CURRENT_BINARY_DIR})

include(GenerateExportHeader)
add_library(track STATIC ${library_sources})
generate_export_header(track)
add_compiler_export_flags()
