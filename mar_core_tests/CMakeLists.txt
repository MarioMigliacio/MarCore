# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(mar_core_tests C)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/../mar_core/inc)
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Create the executable
add_executable(mar_core_tests ${SOURCES})

# Link with the mar_core library
target_link_libraries(mar_core_tests mar_core)

# Set the output directory for the library
set_target_properties(mar_core_tests PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add /Zf compiler option if using MSVC
if(MSVC)
    target_compile_options(mar_core PRIVATE /Zf)
endif()