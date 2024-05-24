cmake_minimum_required(VERSION 3.10)
project(DSA)

# GoogleTest requires at least C++14
# set(CMAKE_CXX_STANDARD 14)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)

#include(FindGTest)
#find_package(GTest CONFIG REQUIRED COMPONENTS GTest GMock)

#include(FetchContent)
#FetchContent_Declare(
#  googletest
#  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
#)
#FetchContent_MakeAvailable(googletest)

include_directories(common)
include_directories(${CMAKE_SOURCE_DIR}/algorithm)

set(ALGO_DIR ${CMAKE_SOURCE_DIR}/algorithm)

set(ALGO_SRC ${ALGO_DIR}/backtracking.cpp)

add_executable(DSA 
  main.cpp 
  ${ALGO_SRC}
)

# enable_testing()
# set(TEST_SRC ${CMAKE_SOURCE_DIR}/test)
# add_executable(testing ${TEST_SRC}/backtracking.cpp)
# target_link_libraries(testing GTest::gtest_main GTest::GTest)
# include(GoogleTest)
# gtest_discover_tests(testing)

