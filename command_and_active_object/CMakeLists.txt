cmake_minimum_required(VERSION 3.15)

project(CommandAndActiveObject LANGUAGES CXX)

add_library(command_and_active_object_lib STATIC
                active_object_engine.cpp
                command.cpp
                delayed_typer.cpp
                sleep_command.cpp
                stop_command.cpp)

target_include_directories(command_and_active_object_lib PUBLIC . ../utils)
target_compile_features(command_and_active_object_lib PUBLIC cxx_std_11)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC command_and_active_object_lib)
