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
#define TEST_CONSTANT_1000000 100000

/**
 * \brief Macro to extract filename from __FILE__
 *
 * \details Since the __FILE__ macro expands the fully qualified path and filename,
 *          it can be excessively large for the output file. Use __FILENAME__ for short
 */
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__))

/**
 * \brief Used to start a unit test for good formatting purposes
 */
#define TEST_INIT() printf("Beginning Test: %s\n", __FUNCTION__)

/**
 * \brief Used to end a unit test for good formatting purposes
 */
#define TEST_TEARDOWN(fail) \
if ((fail) > 0) { \
    printf("%s failed %d assertion(s).\n\n", __FUNCTION__, fail); \
} else { \
    printf("%s passed all assertions.\n\n", __FUNCTION__); \
}

/**
 * \brief Assert that actual value is exactly equal to expected value
 */
#define ASSERT_EQUAL_INT64(actual, expected, fail) \
if ((actual) == (expected)) { \
    printf("[PASSED]:[ASSERT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - line: %d.\n", ((int64_t)actual), ((int64_t)expected), __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - line: %d.\n", ((int64_t)actual), ((int64_t)expected), __LINE__); \
    fail++; \
}

/**
 * \brief Assert that actual value doesn't equal expected value
 */
#define ASSERT_NOT_EQUAL_INT64(actual, expected, fail) \
if ((actual) != (expected)) { \
    printf("[PASSED]:[ASSERT_NOT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - line: %d.\n", ((int64_t)actual), ((int64_t)expected), __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_NOT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - line: %d.\n", ((int64_t)actual), ((int64_t)expected), __LINE__); \
    fail++; \
}

/**
 * \brief Assert that actual value is exactly equal to expected value
 */
#define ASSERT_EQUAL_UINT64(actual, expected, fail) \
if ((actual) == (expected)) { \
    printf("[PASSED]:[ASSERT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - line: %d.\n", ((uint64_t)actual), ((uint64_t)expected), __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - line: %d.\n", ((uint64_t)actual), ((uint64_t)expected), __LINE__); \
    fail++; \
}

/**
 * \brief Assert that actual value doesn't equal expected value
 */
#define ASSERT_NOT_EQUAL_UINT64(actual, expected, fail) \
if ((actual) != (expected)) { \
    printf("[PASSED]:[ASSERT_NOT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - line: %d.\n", ((uint64_t)actual), ((uint64_t)expected), __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_NOT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - line: %d.\n", ((uint64_t)actual), ((uint64_t)expected), __LINE__); \
    fail++; \
}

/**
 * \brief Assert that condition is true
 */
#define ASSERT_TRUE(condition, fail) \
if ((condition)) { \
    printf("[PASSED]:[ASSERT_TRUE] - (condition is true) - line: %d.\n", __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_TRUE] - (condition is false) - line: %d.\n", __LINE__); \
    fail++; \
}

/**
 * \brief Assert that condition is false
 */
#define ASSERT_FALSE(condition, fail) \
if (!(condition)) { \
    printf("[PASSED]:[ASSERT_FALSE] - (condition is false) - line: %d.\n", __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_FALSE] - (condition is true) - line: %d.\n", __LINE__); \
    fail++; \
}

/**
 * \brief Assert that pointer is NULL
 */
#define ASSERT_NULL(pointer, fail) \
if ((pointer) == NULL) { \
    printf("[PASSED]:[ASSERT_NULL] - (pointer is NULL) - line: %d.\n", __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_NULL] - (pointer is not NULL) - line: %d.\n", __LINE__); \
    fail++; \
}

/**
 * \brief Assert that pointer is not NULL
 */
#define ASSERT_NOT_NULL(pointer, fail) \
if ((pointer) != NULL) { \
    printf("[PASSED]:[ASSERT_NOT_NULL] - (pointer is not NULL) - line: %d.\n", __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_NOT_NULL] - (pointer is NULL) - line: %d.\n", __LINE__); \
    fail++; \
}

/**
 * \brief Assert that string compare of actual and expected are identical
 */
#define ASSERT_STRING_EQUAL(actual, expected, str_len, fail) \
if (strncmp((actual), (expected), (str_len)) == 0) { \
    printf("[PASSED]:[ASSERT_STRING_EQUAL] - (actual: %s, expected: %s) - line: %d.\n", (actual), (expected), __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_STRING_EQUAL] - (actual: %s, expected: %s) - line: %d.\n", (actual), (expected), __LINE__); \
    fail++; \
}

/**
 * \brief Assert that string compare of actual and expected are not identical
 */
#define ASSERT_STRING_NOT_EQUAL(actual, expected, str_len, fail) \
if (strncmp((actual), (expected), (str_len)) != 0) { \
    printf("[PASSED]:[ASSERT_STRING_NOT_EQUAL] - (actual: %s, expected: %s) - line: %d.\n", (actual), (expected), __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_STRING_NOT_EQUAL] - (actual: %s, expected: %s) - line: %d.\n", (actual), (expected), __LINE__); \
    fail++; \
}

/**
 * \brief Assert that actual value is within tolerance of expected value
 */
#define ASSERT_DOUBLE_EQUAL(actual, expected, tolerance, fail) \
if (fabs((actual) - (expected)) <= (tolerance)) { \
    printf("[PASSED]:[ASSERT_DOUBLE_EQUAL] - (actual: %f, expected: %f, tolerance: %f) - line: %d.\n", (actual), (expected), (tolerance), __LINE__); \
} else { \
    printf("[FAILED]:[ASSERT_DOUBLE_EQUAL] - (actual: %f, expected: %f, tolerance: %f) - line: %d.\n", (actual), (expected), (tolerance), __LINE__); \
    fail++; \
}

/**
 * \brief Assert that actual array has the same contents as expected array
 */
#define ASSERT_ARRAY_EQUAL(actual, expected, length, fail) \
{ \
    int __assert_array_equal_passed = 1; \
    for (size_t __i = 0; __i < (length); ++__i) { \
        if ((actual)[__i] != (expected)[__i]) { \
            __assert_array_equal_passed = 0; \
            break; \
        } \
    } \
    if (__assert_array_equal_passed) { \
        printf("[PASSED]:[ASSERT_ARRAY_EQUAL] - (arrays are equal) - line: %d.\n", __LINE__); \
    } else { \
        printf("[FAILED]:[ASSERT_ARRAY_EQUAL] - (arrays are not equal) - line: %d.\n", __LINE__); \
        fail++; \
    } \
}

#endif
