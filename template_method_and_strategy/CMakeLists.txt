cmake_minimum_required(VERSION 3.15)

project(TemplateMethodAndStrategy LANGUAGES CXX)

option(BUILD_TESTS "Build the tests..." ON)

add_library(template_method_and_strategy_lib STATIC
                application.cpp
                ftoc_template_method.cpp)

target_include_directories(template_method_and_strategy_lib PUBLIC . ../utils)
target_compile_features(template_method_and_strategy_lib PUBLIC cxx_std_11)

add_executable(template_method_and_strategy main.cpp)
target_link_libraries(template_method_and_strategy PUBLIC template_method_and_strategy_lib)

add_custom_command(TARGET template_method_and_strategy POST_BUILD
                    COMMAND ${CMAKE_COMMAND} -E copy
                            ${CMAKE_CURRENT_SOURCE_DIR}/fahr.txt
                            ${CMAKE_CURRENT_BINARY_DIR}/fahr.txt)