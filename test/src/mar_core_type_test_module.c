/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_core_type_test_module.c                                                            */
/* \brief: Source code for testing mar_core_type                                                 */
/*                                                                                               */
/* \Expects: mar_core_type definitions are defined and linked properly                           */
/*                                                                                               */
/*           Unit tests should follow a step by step approach and be specific to the             */
/*           name of the function which they are evoked.                                         */
/*           1. Setup - Stage the entities to be tested on                                       */
/*           2. Act - If necessary, perform any routines that might be necessary                 */
/*           3. Assert - Determine if expectations are met for the test                          */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mar_core_test.h"

/*
 * \brief Test type Unsigned Max Values Are Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_UnsignedMaxValuesAreExpected(void)
{
    /* Setup */
    u8 maxU8   =  U8_MAX;
    u16 maxU16 = U16_MAX;
    u32 maxU32 = U32_MAX;
    u64 maxU64 = U64_MAX;

    /* Act */

    /* Assert */
    ASSERT_EQUAL_UINT64(maxU8,   UINT8_MAX);
    ASSERT_EQUAL_UINT64(maxU16, UINT16_MAX);
    ASSERT_EQUAL_UINT64(maxU32, UINT32_MAX);
    ASSERT_EQUAL_UINT64(maxU64, UINT64_MAX);
}

/*
 * \brief Test type Unsigned Overflow Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_UnsignedOverflowExpected(void)
{
    /* Setup */
    u8 maxU8   =  U8_MAX;
    u16 maxU16 = U16_MAX;
    u32 maxU32 = U32_MAX;
    u64 maxU64 = U64_MAX;

    /* Act */
    maxU8  += 1;
    maxU16 += 1;
    maxU32 += 1;
    maxU64 += 1;

    /* Assert */
    ASSERT_NOT_EQUAL_UINT64(maxU8,   UINT8_MAX);
    ASSERT_NOT_EQUAL_UINT64(maxU16, UINT16_MAX);
    ASSERT_NOT_EQUAL_UINT64(maxU32, UINT32_MAX);
    ASSERT_NOT_EQUAL_UINT64(maxU64, UINT64_MAX);
}

/*
 * \brief Test type Signed Min Values Are Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_SignedMinValuesAreExpected(void)
{
    /* Setup */
    i8 minI8   =  I8_MIN;
    i16 minI16 = I16_MIN;
    i32 minI32 = I32_MIN;
    i64 minI64 = I64_MIN;

    /* Act */

    /* Assert */
    ASSERT_EQUAL_INT64(minI8,   INT8_MIN);
    ASSERT_EQUAL_INT64(minI16, INT16_MIN);
    ASSERT_EQUAL_INT64(minI32, INT32_MIN);
    ASSERT_EQUAL_INT64(minI64, INT64_MIN);
}

/*
 * \brief Test type Signed Max Values Are Expected
 *
 * \details Stress the type definitions and values
 */
void Test_mar_core_type_SignedMaxValuesAreExpected(void)
{
    /* Setup */
    i8 maxI8   =  I8_MAX;
    i16 maxI16 = I16_MAX;
    i32 maxI32 = I32_MAX;
    i64 maxI64 = I64_MAX;

    /* Act */

    /* Assert */
    ASSERT_EQUAL_INT64(maxI8,   INT8_MAX);
    ASSERT_EQUAL_INT64(maxI16, INT16_MAX);
    ASSERT_EQUAL_INT64(maxI32, INT32_MAX);
    ASSERT_EQUAL_INT64(maxI64, INT64_MAX);
}

/*
 * \brief Main exposed module for all unit tests of type mario_core_type
 *
 * \details Package all the mar core type unit tests
 */
void Run_Test_Module_Mar_Core_Type(void)
{
    Test_mar_core_type_UnsignedMaxValuesAreExpected();
    Test_mar_core_type_UnsignedOverflowExpected();
    Test_mar_core_type_SignedMinValuesAreExpected();
    Test_mar_core_type_SignedMaxValuesAreExpected();
}

/*
 * \brief Run All Tests runs every module that has defined unit tests.
 */
void Run_All_Tests(void)
{
    /* Safekeeping with global file pointer */
    OPEN_TEST_OUTPUT_FILE();

    /* Add each Run_Test_Module here */
    Run_Test_Module_Mar_Core_Type();

    /* Safekeeping with global file pointer */
    CLOSE_TEST_OUTPUT_FILE();
}
