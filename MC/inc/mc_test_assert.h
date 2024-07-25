/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test_assert.h                                                                       */
/* \brief: Utility functionality Macros for test assertions                                      */
/*                                                                                               */
/* \Expects: 1. mc_test_file.h is linked properly                                                */
/*           2. Prior to calling ASSERT macros, the dump output file should be instantiated      */
/*           Through calling OPEN_TEST_OUTPUT_FILE(). Leaving a matching call to                 */
/*           CLOSE_TEST_OUTPUT_FILE() when finished.                                             */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TEST_ASSERT_H
#define MC_TEST_ASSERT_H

#include "mc_type.h"
#include <stdio.h>              // printf
#include <string.h>             // strncmp
#include <math.h>               // fabs (absolute value floating point)
#include <inttypes.h>           // handle 64 bit sizes in format strings without warning

/**
 * \brief A magic number determined to be good enough for a small sample size of HashMap
 */
#define TEST_CONSTANT_10 10

/**
 * \brief A magic number determined to be good enough for a small sample size of HashMap allocations
 */
#define TEST_CONSTANT_32 32

/**
 * \brief A magic number determined to be good enough for a large sample size of HashMap allocations
 */
#define TEST_CONSTANT_1000000 1000000

/**
 * \brief Macro to extract filename from __FILE__
 *
 * \details Since the __FILE__ macro expands the fully qualified path and filename,
 *          it can be excessively large for the output file. Use __FILENAME__ for short
 */
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__))

/**
 * \brief Assert that actual value is exactly equal to expected value
 */
u8 ASSERT_EQUAL_INT64(i64 actual, i64 expected);

/**
 * \brief Assert that actual value doesn't equal expected value
 */
u8 ASSERT_NOT_EQUAL_INT64(i64 actual, i64 expected);

/**
 * \brief Assert that actual value is exactly equal to expected value
 */
u8 ASSERT_EQUAL_UINT64(u64 actual, u64 expected);

/**
 * \brief Assert that actual value doesn't equal expected value
 */
u8 ASSERT_NOT_EQUAL_UINT64(u64 actual, u64 expected);

/**
 * \brief Assert that condition is true
 */
u8 ASSERT_TRUE(bool condition);

/**
 * \brief Assert that condition is false
 */
u8 ASSERT_FALSE(bool condition);

/**
 * \brief Assert that pointer is NULL
 */
u8 ASSERT_NULL(void* pointer);

/**
 * \brief Assert that pointer is not NULL
 */
u8 ASSERT_NOT_NULL(void* pointer);

/**
 * \brief Assert that string compare of actual and expected are identical
 */
u8 ASSERT_STRING_EQUAL(char* actual, char* expected, u64 str_len);

/**
 * \brief Assert that string compare of actual and expected are not identical
 */
u8 ASSERT_STRING_NOT_EQUAL(char* actual, char* expected, u64 str_len);

/**
 * \brief Assert that actual value is within tolerance of expected value
 */
u8 ASSERT_DOUBLE_EQUAL(float actual, float expected, float tolerance);

#endif
