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

#include "mc_test_file.h"       // PRINT_TO_FILE
#include <inttypes.h>           // handle 64 bit sizes in format strings without warning
#include <string.h>             // strncmp
#include <math.h>               // fabs (absolute value floating point)

/**
 * \brief A magic number determined to be good enough for a small sample size of HashMap
 */
#define TEST_SMALL_CONSTANT 10

/**
 * \brief A magic number determined to be good enough for a small sample size of HashMap allocations
 */
#define TEST_MID_CONSTANT 32

/**
 * \brief A magic number determined to be good enough for a large sample size of HashMap allocations
 */
#define TEST_HUGE_CONSTANT 1000000

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
#define ASSERT_EQUAL_INT64(actual, expected) \
if ((actual) == (expected)) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that actual value doesn't equal expected value
 */
#define ASSERT_NOT_EQUAL_INT64(actual, expected) \
if ((actual) != (expected)) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_NOT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_NOT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that actual value is exactly equal to expected value
 */
#define ASSERT_EQUAL_UINT64(actual, expected) \
if ((actual) == (expected)) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that actual value doesn't equal expected value
 */
#define ASSERT_NOT_EQUAL_UINT64(actual, expected) \
if ((actual) != (expected)) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_NOT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_NOT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that condition is true
 */
#define ASSERT_TRUE(condition) \
if ((condition)) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_TRUE] - (condition is true) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_TRUE] - (condition is false) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that condition is false
 */
#define ASSERT_FALSE(condition) \
if (!(condition)) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_FALSE] - (condition is false) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_FALSE] - (condition is true) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that pointer is NULL
 */
#define ASSERT_NULL(pointer) \
if ((pointer) == NULL) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_NULL] - (pointer is NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_NULL] - (pointer is not NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that pointer is not NULL
 */
#define ASSERT_NOT_NULL(pointer) \
if ((pointer) != NULL) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_NOT_NULL] - (pointer is not NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_NOT_NULL] - (pointer is NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that string compare of actual and expected are identical
 */
#define ASSERT_STRING_EQUAL(actual, expected, str_len) \
if (strncmp((actual), (expected), (str_len)) == 0) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_STRING_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_STRING_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that string compare of actual and expected are not identical
 */
#define ASSERT_STRING_NOT_EQUAL(actual, expected, str_len) \
if (strncmp((actual), (expected), (str_len)) != 0) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_STRING_NOT_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_STRING_NOT_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that actual value is within tolerance of expected value
 */
#define ASSERT_DOUBLE_EQUAL(actual, expected, tolerance) \
if (fabs((actual) - (expected)) <= (tolerance)) { \
    PRINT_TO_FILE("%s: [PASSED]:[ASSERT_DOUBLE_EQUAL] - (actual: %f, expected: %f, tolerance: %f) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), (tolerance), __FILENAME__, __LINE__); \
} else { \
    PRINT_TO_FILE("%s: [FAILED]:[ASSERT_DOUBLE_EQUAL] - (actual: %f, expected: %f, tolerance: %f) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), (tolerance), __FILENAME__, __LINE__); \
}

/**
 * \brief Assert that actual array has the same contents as expected array
 */
#define ASSERT_ARRAY_EQUAL(actual, expected, length) \
{ \
    int __assert_array_equal_passed = 1; \
    for (size_t __i = 0; __i < (length); ++__i) { \
        if ((actual)[__i] != (expected)[__i]) { \
            __assert_array_equal_passed = 0; \
            break; \
        } \
    } \
    if (__assert_array_equal_passed) { \
        PRINT_TO_FILE("%s: [PASSED]:[ASSERT_ARRAY_EQUAL] - (arrays are equal) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
    } else { \
        PRINT_TO_FILE("%s: [FAILED]:[ASSERT_ARRAY_EQUAL] - (arrays are not equal) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
    } \
}

#endif
