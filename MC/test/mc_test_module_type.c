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
/*           1. Arrange - Stage the entities to be tested on                                     */
/*           2. Act - If necessary, perform any routines that might be necessary                 */
/*           3. Assert - Determine if expectations are met for the test                          */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mc_test.h"

/**
 * \brief An internal table that is useful in testing a large array of bitmasks
 */
static u64 lookupTable[64] = {
    MASK_0, MASK_1, MASK_2, MASK_3, MASK_4, MASK_5, MASK_6, MASK_7,
    MASK_8, MASK_9, MASK_10, MASK_11, MASK_12, MASK_13, MASK_14, MASK_15,
    MASK_16, MASK_17, MASK_18, MASK_19, MASK_20, MASK_21, MASK_22, MASK_23,
    MASK_24, MASK_25, MASK_26, MASK_27, MASK_28, MASK_29, MASK_30, MASK_31,
    MASK_32, MASK_33, MASK_34, MASK_35, MASK_36, MASK_37, MASK_38, MASK_39,
    MASK_40, MASK_41, MASK_42, MASK_43, MASK_44, MASK_45, MASK_46, MASK_47,
    MASK_48, MASK_49, MASK_50, MASK_51, MASK_52, MASK_53, MASK_54, MASK_55,
    MASK_56, MASK_57, MASK_58, MASK_59, MASK_60, MASK_61, MASK_62, MASK_63
};

void Test_MC_Type_UintMaxValsCorrect(void)
{
    /* Arrange */
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
    /* Arrange */
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
    /* Arrange */
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
    /* Arrange */
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

void Test_MC_Type_SetBitCorrect(void)
{
    /* Arrange */
    u64 testUint = 0;

    /* Act */

    /* Assert */
    for (u8 i = 0; i < 64; i++)     // set every bit to 1
    {
        ASSERT_EQUAL_UINT64(testUint, lookupTable[i]);
        testUint = 0;
        testUint = SET_BIT(testUint, i);
    }
}

void Test_MC_Type_ClearBitCorrect(void)
{
    /* Arrange */
    u64 testUint;

    /* Act */

    /* Assert */
    for (u8 i = 0; i < 64; i++)     // clear every bit to 0
    {
        testUint = lookupTable[i];
        CLEAR_BIT(testUint, i - 1);         // reminder that bit position starts from 0, so sub 1 for correct shift index.
        ASSERT_EQUAL_UINT64(testUint, 0);
    }
}

void Test_MC_Type_ToggleBitCorrect(void)
{
    /* Arrange */
    u8 testUint = U8_MAX;

    /* Act */
    for (u8 i = 0; i < 8; i++)  // toggle every bit to 0
    {
        TOGGLE_BIT(testUint, i);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(testUint, 0);

    for (u8 i = 0; i < 8; i++)  // toggle every bit back to 1
    {
        TOGGLE_BIT(testUint, i);
    }

    ASSERT_EQUAL_UINT64(testUint, U8_MAX);
}

void Test_MC_Type_IsBitSetCorrect(void)
{
    /* Arrange */
    u8 testUint = 0b10101010;

    /* Act */

    /* Assert */
    for (u8 i = 0; i < 8; i++)
    {
        if (i % 2 == 0) // even indexes are 0s
        {
            ASSERT_TRUE(IS_BIT_SET(testUint, i) == 0);
        }
        else
        {
            ASSERT_TRUE(IS_BIT_SET(testUint, i) != 0);
        }
    }
}

int main(void)
{
    Test_MC_Type_UintMaxValsCorrect();
    Test_MC_Type_UintMaxOverflowCorrect();
    Test_MC_Type_IntMinValsCorrect();
    Test_MC_Type_IntMaxValsCorrect();
    Test_MC_Type_SetBitCorrect();
    Test_MC_Type_ClearBitCorrect();
    Test_MC_Type_ToggleBitCorrect();
    Test_MC_Type_IsBitSetCorrect();

    return 0;
}
