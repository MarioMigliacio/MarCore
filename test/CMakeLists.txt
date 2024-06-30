# test/CMakeLists.txt

# Test executable
file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/src/*.c")

# Add the /inc directory to the include path
include_directories(inc)
include_directories(../inc)

# Add the test executable
add_executable(mario_core_test ${TEST_SOURCES})

# Add test to CTest
add_test(NAME mario_core_test COMMAND mario_core_test)