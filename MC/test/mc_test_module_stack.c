/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test_module_stack.c                                                                 */
/* \brief: Source code for testing mc_stack                                                      */
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

u32 Test_MC_Stack_InitAndFree(void)
{
    /* Arrange */
    TEST_INIT();
    
    u32 failCount = 0;
    MC_Stack *stack = MC_Stack_Init();

    ASSERT_NOT_NULL(stack, failCount);

    /* Act */
    MC_Stack_Free(&stack);

    /* Assert */
    ASSERT_NULL(stack, failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

u32 Test_MC_Stack_BigSize(void)
{
    /* Arrange*/
    TEST_INIT();
    
    u32 failCount = 0;
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char value[TEST_CONSTANT_32];
    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(stack, failCount);

    /* Act */
    for (u64 i = 0; i < TEST_CONSTANT_1000000; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %lld", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, false);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_CONSTANT_1000000, failCount);

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack, failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

u32 Test_MC_Stack_DynamicInsertion(void)
{
    /* Arrange */
    TEST_INIT();
    
    u32 failCount = 0;
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(stack, failCount);

    /* Act */
    for (u8 i = 0; i < TEST_CONSTANT_32; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        char *value = _strdup(temp);

        successfulPushes += MC_Stack_Push(stack, value, true);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_CONSTANT_32, failCount);

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack, failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

u32 Test_MC_Stack_PeekAndPop(void)
{
    /* Arrange */
    TEST_INIT();
    
    u32 failCount = 0;
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char value[TEST_CONSTANT_32];
    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(stack, failCount);

    /* Act */
    /* Assert */
    for (u8 i = 0; i < TEST_CONSTANT_32; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, false);

        ASSERT_STRING_EQUAL((char*)MC_Stack_Peek(stack), value, strlen(value), failCount);
        MC_Stack_Pop(stack);
    }
    
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_CONSTANT_32, failCount);

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack, failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

u32 Test_MC_Stack_IsEmpty(void)
{
    /* Arrange */
    TEST_INIT();
    
    u32 failCount = 0;
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char value[TEST_CONSTANT_32];
    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(stack, failCount);
    ASSERT_TRUE(MC_Stack_IsEmpty(stack), failCount);

    /* Act */
    for (u8 i = 0; i < TEST_CONSTANT_10; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, false);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_CONSTANT_10, failCount);
    ASSERT_FALSE(MC_Stack_IsEmpty(stack), failCount);

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack, failCount);
    ASSERT_TRUE(MC_Stack_IsEmpty(stack), failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

u32 Test_MC_Stack_GetSize(void)
{
    /* Arrange */
    TEST_INIT();
    
    u32 failCount = 0;
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;
    u64 successfulPops = 0;

    char value[TEST_CONSTANT_32];
    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(stack, failCount);
    ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), 0, failCount);

    /* Act */
    /* Assert */
    for (u8 i = 0; i < TEST_CONSTANT_32; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, false);
        ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), successfulPushes, failCount);
    }

    for (u8 i = 0; i < TEST_CONSTANT_32; i++)
    {
        if (MC_Stack_Pop(stack) != NULL)
        {
            successfulPops++;
        }

        ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), successfulPushes - successfulPops, failCount);
    }

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack, failCount);
    ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), 0, failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

int main(void)
{
    int failCount = 0;

    failCount += Test_MC_Stack_InitAndFree();
    failCount += Test_MC_Stack_BigSize();
    failCount += Test_MC_Stack_DynamicInsertion();
    failCount += Test_MC_Stack_PeekAndPop();
    failCount += Test_MC_Stack_IsEmpty();
    failCount += Test_MC_Stack_GetSize();

    return failCount;
}
