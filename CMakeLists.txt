# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(mario_core VERSION 1.0 LANGUAGES C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Set the output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Add the executable
add_executable(mario_core ${SOURCES})

# Link libraries (if any)
# target_link_libraries(mario_core mylibrary)

# Testing setup
enable_testing()

# Add tests subdirectory
add_subdirectory(test)

# Test source files
file(GLOB_RECURSE TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*.c")

# Custom targets for building, cleaning, testing, and running
add_custom_target(run
    COMMAND mario_core
    DEPENDS mario_core
    WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)

add_custom_target(clean_all
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_BINARY_DIR}/cmake_clean.cmake
)

add_custom_target(test_all
    COMMAND ${CMAKE_CTEST_COMMAND}
    DEPENDS ${TEST_SOURCES}
)

# Generate a clean script
file(WRITE ${CMAKE_BINARY_DIR}/cmake_clean.cmake
"file(GLOB_RECURSE files \"${CMAKE_BINARY_DIR}/*\")
foreach(file \${files})
    file(REMOVE \${file})
endforeach()
")

# Create build directory if it doesn't exist
if(NOT EXISTS ${CMAKE_BINARY_DIR})
    file(MAKE_DIRECTORY ${CMAKE_BINARY_DIR})
endif()
