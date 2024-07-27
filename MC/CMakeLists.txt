# Set the project name
project(MC)

# Specify the c standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)

# Add the Source files
file(GLOB_RECURSE SOURCES "src/*.c")
file(GLOB_RECURSE HEADERS "inc/*.h")

# Create the library
add_library(MC ${SOURCES} ${HEADERS})

# Link the necessary Windows library for GUID generation
target_link_libraries(MC ole32)

# Specify include directoryies for users of this library
target_include_directories(MC PUBLIC inc)

# Set the output directory for the library
set_target_properties(MC PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
)

# Add tests using CTest
enable_testing()
add_subdirectory(test)
