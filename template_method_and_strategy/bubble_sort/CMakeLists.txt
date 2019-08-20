cmake_minimum_required(VERSION 3.15)

project(FtoC LANGUAGES CXX)

option(BUILD_TESTS "Build the tests..." ON)

set(BIN_NAME bubble_sort)

add_library(${BIN_NAME}_lib STATIC
                bubble_sorter.cpp
                double_bubble_sorter.cpp
                int_bubble_sorter.cpp)

target_include_directories(${BIN_NAME}_lib PUBLIC . ${CMAKE_SOURCE_DIR}/utils)
target_compile_features(${BIN_NAME}_lib PUBLIC cxx_std_11)

add_executable(${BIN_NAME} main.cpp)
target_link_libraries(${BIN_NAME} PUBLIC ${BIN_NAME}_lib)
