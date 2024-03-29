cmake_minimum_required(VERSION 3.15)

project(CommandAndActiveObject LANGUAGES CXX)

option(BUILD_TESTS "Build the tests..." ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()

set(BIN_NAME command_and_active_object)

add_library(${BIN_NAME}_lib STATIC
                active_object_engine.cpp
                command.cpp
                delayed_typer.cpp
                sleep_command.cpp
                stop_command.cpp)

target_include_directories(${BIN_NAME}_lib PUBLIC . ${CMAKE_SOURCE_DIR}/utils)
target_compile_features(${BIN_NAME}_lib PUBLIC cxx_std_11)

add_executable(${BIN_NAME} main.cpp)
target_link_libraries(${BIN_NAME} PUBLIC ${BIN_NAME}_lib)
