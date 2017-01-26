cmake_minimum_required(VERSION 3.6)
project(rxcpp_examples)

set(CMAKE_CXX_STANDARD 11)

set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)

include_directories(include)

set(SOURCE_FILES src/main.cpp src/SimpleOperators.cpp src/SimpleOperators.h src/SimpleInterface.h)
add_executable(rxcpp_examples ${SOURCE_FILES})