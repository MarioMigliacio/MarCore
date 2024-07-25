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

#include "mc_test_assert.h"

u8 ASSERT_EQUAL_INT64(i64 actual, i64 expected)
{
    if (actual == expected)
    { 
        printf("%s: [PASSED]:[ASSERT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__);
        return 0;
    } 
    else
    {
        printf("%s: [FAILED]:[ASSERT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_NOT_EQUAL_INT64(i64 actual, i64 expected)
{
    if ((actual) != (expected))
    {
        printf("%s: [PASSED]:[ASSERT_NOT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_NOT_EQUAL] - (actual: %" PRId64 ", expected: %" PRId64 ") - %s: line: %d.\n", __FUNCTION__, ((int64_t)actual), ((int64_t)expected), __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_EQUAL_UINT64(u64 actual, u64 expected)
{
    if ((actual) == (expected))
    {
        printf("%s: [PASSED]:[ASSERT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_NOT_EQUAL_UINT64(u64 actual, u64 expected)
{
    if (actual != expected)
    {
        printf("%s: [PASSED]:[ASSERT_NOT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__);
        return 0;
    } 
    else
    {
        printf("%s: [FAILED]:[ASSERT_NOT_EQUAL] - (actual: %" PRIu64 ", expected: %" PRIu64 ") - %s: line: %d.\n", __FUNCTION__, ((uint64_t)actual), ((uint64_t)expected), __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_TRUE(bool condition)
{
    if ((condition))
    {
        printf("%s: [PASSED]:[ASSERT_TRUE] - (condition is true) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_TRUE] - (condition is false) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__); \
        return 1;
    }
}

u8 ASSERT_FALSE(bool condition)
{
    if (!(condition))
    {
        printf("%s: [PASSED]:[ASSERT_FALSE] - (condition is false) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_FALSE] - (condition is true) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_NULL(void* pointer)
{
    if ((pointer) == NULL)
    {
        printf("%s: [PASSED]:[ASSERT_NULL] - (pointer is NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_NULL] - (pointer is not NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_NOT_NULL(void* pointer)
{
    if ((pointer) != NULL)
    {
        printf("%s: [PASSED]:[ASSERT_NOT_NULL] - (pointer is not NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_NOT_NULL] - (pointer is NULL) - %s: line: %d.\n", __FUNCTION__, __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_STRING_EQUAL(char* actual, char* expected, u64 str_len)
{
    if (strncmp(actual, expected, str_len) == 0)
    {
        printf("%s: [PASSED]:[ASSERT_STRING_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_STRING_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_STRING_NOT_EQUAL(char* actual, char* expected, u64 str_len)
{
    if (strncmp(actual, expected, str_len) != 0)
    {
        printf("%s: [PASSED]:[ASSERT_STRING_NOT_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_STRING_NOT_EQUAL] - (actual: %s, expected: %s) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), __FILENAME__, __LINE__);
        return 1;
    }
}

u8 ASSERT_DOUBLE_EQUAL(float actual, float expected, float tolerance)
{
    if (fabs(actual - expected) <= tolerance)
    {
        printf("%s: [PASSED]:[ASSERT_DOUBLE_EQUAL] - (actual: %f, expected: %f, tolerance: %f) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), (tolerance), __FILENAME__, __LINE__);
        return 0;
    }
    else
    {
        printf("%s: [FAILED]:[ASSERT_DOUBLE_EQUAL] - (actual: %f, expected: %f, tolerance: %f) - %s: line: %d.\n", __FUNCTION__, (actual), (expected), (tolerance), __FILENAME__, __LINE__);
        return 1;
    }
}
