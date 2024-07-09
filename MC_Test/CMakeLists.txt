# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(MC_Test C)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/../MC/inc)
include_directories(${PROJECT_SOURCE_DIR}/inc)

# Source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.c")

# Create the executable
add_executable(MC_Test ${SOURCES})

# Link with the MC library
target_link_libraries(MC_Test MC)

# Set the output directory for the library
set_target_properties(MC_Test PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Add /Zf compiler option if using MSVC
if(MSVC)
    target_compile_options(MC_Test PRIVATE /Zf)
endif()