/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test_module_type.c                                                                  */
/* \brief: Source code for testing mc_type                                                       */
/*                                                                                               */
/* \Expects: 1. All necessary mc definitions are defined and linked properly                     */
/*                                                                                               */
/*           Unit tests should follow a step by step approach and be specific to the             */
/*           name of the function which they are evoked.                                         */
/*           1. Setup - Stage the entities to be tested on                                       */
/*           2. Act - If necessary, perform any routines that might be necessary                 */
/*           3. Assert - Determine if expectations are met for the test                          */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mc_test.h"
#include "mc_type.h"
#include "mc_test_file.h"
#include "mc_test_assert.h"

void Test_MC_Type_UintMaxValsCorrect(void)
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

void Test_MC_Type_UintMaxOverflowCorrect(void)
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

void Test_MC_Type_IntMinValsCorrect(void)
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

void Test_MC_Type_IntMaxValsCorrect(void)
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

void Test_MC_Module_Type(void)
{
    Test_MC_Type_UintMaxValsCorrect();
    Test_MC_Type_UintMaxOverflowCorrect();
    Test_MC_Type_IntMinValsCorrect();
    Test_MC_Type_IntMaxValsCorrect();
}

void Run_All_Tests(void)
{
    /* Safekeeping with global file pointer */
    OPEN_TEST_OUTPUT_FILE();

    /* Add each Run_Test_Module here */
    Test_MC_Module_Type();

    /* Safekeeping with global file pointer */
    CLOSE_TEST_OUTPUT_FILE();
}
