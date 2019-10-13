cmake_minimum_required(VERSION 3.15)

project(FtoCStrategy LANGUAGES CXX)

option(BUILD_TESTS "Build the tests..." ON)

set(BIN_NAME f_to_c_strategy)

add_library(${BIN_NAME}_lib STATIC
                application.cpp
                application_runner.cpp
                ftoc_strategy.cpp)

target_include_directories(${BIN_NAME}_lib PUBLIC . ${CMAKE_SOURCE_DIR}/utils)
target_compile_features(${BIN_NAME}_lib PUBLIC cxx_std_11)

add_executable(${BIN_NAME} main.cpp)
target_link_libraries(${BIN_NAME} PUBLIC ${BIN_NAME}_lib)

add_custom_command(TARGET ${BIN_NAME} POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy
                            ${CMAKE_CURRENT_SOURCE_DIR}/fahr.txt
                            ${CMAKE_CURRENT_BINARY_DIR}/fahr.txt)