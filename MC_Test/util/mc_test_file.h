/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test_file.h                                                                         */
/* \brief: Utility functionality Macros for test output file                                     */
/*                                                                                               */
/* \Expects: No expectations are made prior to definition for test file and macros               */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_FILE_H
#define MC_TEST_FILE_H

#include <stdio.h>  // file ops
#include <stdlib.h> // exit failure

/**
 * \brief Test file where output will be written
 */
#define TEST_OUTPUT_FILE "last_test_output.txt"

/**
 * \brief File pointer
 */
static FILE *test_output_stream = NULL;

/**
 * \brief Open the TEST_OUTPUT_FILE for write mode
 */
#define OPEN_TEST_OUTPUT_FILE(mode) \
do { \
    if (fopen_s(&test_output_stream, TEST_OUTPUT_FILE, mode) != 0) { \
        perror("Failed to open test output file"); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

/**
 * \brief Close the TEST_OUTPUT_FILE
 */
#define CLOSE_TEST_OUTPUT_FILE() \
do { \
    if (test_output_stream != NULL) { \
        fclose(test_output_stream); \
    } \
} while (0)

/**
 * \brief Redirect printing to TEST_OUTPUT_FILE stream 
 */
#define PRINT_TO_FILE(fmt, ...) \
do { \
    if (test_output_stream != NULL) { \
        fprintf_s(test_output_stream, fmt, ##__VA_ARGS__); \
    } \
} while (0)

#endif
