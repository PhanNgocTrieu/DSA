cmake_minimum_required(VERSION 3.10)

project(DSA)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

include_directories(common)
include_directories(${CMAKE_SOURCE_DIR}/algorithm)

set(ALGO_DIR ${CMAKE_SOURCE_DIR}/algorithm)

set(ALGO_SRC ${ALGO_DIR}/backtracking.hpp)

add_executable(DSA 
  main.cpp 
  ${ALGO_SRC}
)

# add_executable(testing backtracking.cpp)
# include(GoogleTest)
# gtest_discover_tests(testing)
# FetchContent_MakeAvailable(googletest)

