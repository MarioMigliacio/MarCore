# Set the project name
project(MC_Tests)

# Add include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/util)

file(GLOB_RECURSE TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/*.c")

# Iterate over each source file to create a test executable
foreach(TEST_SOURCE ${TEST_SOURCES})
    # Get the filename without the directory
    get_filename_component(TEST_NAME ${TEST_SOURCE} NAME_WE)
    
    # Create an executable for the test
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    
    # Link the library to the test executable
    target_link_libraries(${TEST_NAME} MC)
    
    # Set the output directories for the test executable
    set_target_properties(${TEST_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>"
    )
    
    # Add the test to ctest
    add_test(NAME ${TEST_NAME} COMMAND $<TARGET_FILE:${TEST_NAME}>)
endforeach()
