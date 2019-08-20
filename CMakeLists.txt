cmake_minimum_required(VERSION 3.15)

project(AgileSoftwareDevelopment LANGUAGES CXX)

set(CMAKE_VERBOSE_MAKEFILE OFF)

add_subdirectory("${PROJECT_SOURCE_DIR}/extern/googletest")

add_subdirectory(command_and_active_object)
add_subdirectory(template_method_and_strategy)
