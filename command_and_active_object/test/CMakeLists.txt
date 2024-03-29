cmake_minimum_required(VERSION 3.15)

macro(add_package_test TEST_NAME SRC_LIB)
    add_executable(${TEST_NAME} ${ARGN})
    target_link_libraries(${TEST_NAME} ${SRC_LIB} gtest gmock gtest_main)
    add_test(NAME ${TEST_NAME} COMMAND ${TEST_NAME})
    set_target_properties(${TEST_NAME} PROPERTIES FOLDER tests)
endmacro()

set(UNIT_TEST_TARGET test_sleep_command)

add_package_test(${UNIT_TEST_TARGET} command_and_active_object_lib test_sleep_command.cpp)

add_custom_command(
    TARGET ${UNIT_TEST_TARGET} POST_BUILD
    COMMENT "Running ${UNIT_TEST_TARGET}"
    COMMAND ${UNIT_TEST_TARGET}
)