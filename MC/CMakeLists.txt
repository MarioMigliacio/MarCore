# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(MC C)

# Specify the C standard
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Create the library
add_library(MC STATIC ${SOURCES})

# Specify include directoryies for users of this library
target_include_directories(MC PUBLIC ${PROJECT_SOURCE_DIR}/inc)

# Set the output directory for the library
set_target_properties(MC PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add /Zf compiler option if using MSVC
if(MSVC)
    target_compile_options(MC PRIVATE /Zf)
endif()