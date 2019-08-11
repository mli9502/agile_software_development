cmake_minimum_required(VERSION 3.15)

message(STATUS "source: ${PROJECT_SOURCE_DIR}")

add_subdirectory("${PROJECT_SOURCE_DIR}/../extern/googletest" "extern/googletest")

mark_as_advanced(
    BUILD_GMOCK BUILD_GTEST BUILD_SHARED_LIBS
    gmock_build_tests gtest_build_samples gtest_build_tests
    gtest_disable_pthreads gtest_force_shared_crt gtest_hide_internal_symbols
)

macro(add_package_test TEST_NAME SRC_LIB)
    add_executable(${TEST_NAME} ${ARGN})
    target_link_libraries(${TEST_NAME} ${SRC_LIB} gtest gmock gtest_main)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    set_target_properties(${TEST_NAME} PROPERTIES FOLDER tests)
endmacro()

add_package_test(test_sleep_command command_and_active_object_lib test_sleep_command.cpp)