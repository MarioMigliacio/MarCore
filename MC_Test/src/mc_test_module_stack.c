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

#include "mc_stack.h"
#include "mc_type.h"
#include "mc_test_stack.h"
#include "mc_test_assert.h"

void Test_MC_Stack_InitAndFree(void)
{
    /* Arrange */
    MC_Stack *stack = MC_Stack_Init();

    ASSERT_NOT_NULL(stack);

    /* Act */
    MC_Stack_Free(&stack);

    /* Assert */
    ASSERT_NULL(stack);
}

void Test_MC_Stack_BigSize(void)
{
    /* Arrange*/
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char value[TEST_MID_CONSTANT];
    char temp[TEST_MID_CONSTANT];

    ASSERT_NOT_NULL(stack);

    /* Act */
    for (u64 i = 0; i < TEST_HUGE_CONSTANT; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %lld", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, FALSE);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_HUGE_CONSTANT);

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack);
}

void Test_MC_Stack_DynamicInsertion(void)
{
    /* Arrange */
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char temp[TEST_MID_CONSTANT];

    ASSERT_NOT_NULL(stack);

    /* Act */
    for (u8 i = 0; i < TEST_MID_CONSTANT; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        char *value = _strdup(temp);

        successfulPushes += MC_Stack_Push(stack, value, TRUE);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_MID_CONSTANT);

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack);
}

void Test_MC_Stack_PeekAndPop(void)
{
    /* Arrange */
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char value[TEST_MID_CONSTANT];
    char temp[TEST_MID_CONSTANT];

    ASSERT_NOT_NULL(stack);

    /* Act */
    /* Assert */
    for (u8 i = 0; i < TEST_MID_CONSTANT; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, FALSE);

        ASSERT_STRING_EQUAL((char*)MC_Stack_Peek(stack), value, strlen(value));
        MC_Stack_Pop(stack);
    }
    
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_MID_CONSTANT);

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack);
}

void Test_MC_Stack_IsEmpty(void)
{
    /* Arrange */
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;

    char value[TEST_MID_CONSTANT];
    char temp[TEST_MID_CONSTANT];

    ASSERT_NOT_NULL(stack);
    ASSERT_TRUE(MC_Stack_IsEmpty(stack));

    /* Act */
    for (u8 i = 0; i < TEST_SMALL_CONSTANT; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, FALSE);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(successfulPushes, TEST_SMALL_CONSTANT);
    ASSERT_FALSE(MC_Stack_IsEmpty(stack));

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack);
    ASSERT_TRUE(MC_Stack_IsEmpty(stack));
}

void Test_MC_Stack_GetSize(void)
{
    /* Arrange */
    MC_Stack *stack = MC_Stack_Init();
    u64 successfulPushes = 0;
    u64 successfulPops = 0;

    char value[TEST_MID_CONSTANT];
    char temp[TEST_MID_CONSTANT];

    ASSERT_NOT_NULL(stack);
    ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), 0);

    /* Act */
    /* Assert */
    for (u8 i = 0; i < TEST_MID_CONSTANT; i++)
    {
        sprintf_s(temp, sizeof(temp), "Stack push: %d", i);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulPushes += MC_Stack_Push(stack, value, FALSE);
        ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), successfulPushes);
    }

    for (u8 i = 0; i < TEST_MID_CONSTANT; i++)
    {
        if (MC_Stack_Pop(stack) != NULL)
        {
            successfulPops++;
        }

        ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), successfulPushes - successfulPops);
    }

    MC_Stack_Free(&stack);

    ASSERT_NULL(stack);
    ASSERT_EQUAL_UINT64(MC_Stack_Size(stack), 0);
}

void Test_MC_Module_Stack(void)
{
    /* Safekeeping with global file pointer */
    OPEN_TEST_OUTPUT_FILE("a");

    Test_MC_Stack_InitAndFree();
    Test_MC_Stack_BigSize();
    Test_MC_Stack_DynamicInsertion();
    Test_MC_Stack_PeekAndPop();
    Test_MC_Stack_IsEmpty();
    Test_MC_Stack_GetSize();

    /* Safekeeping with global file pointer */
    CLOSE_TEST_OUTPUT_FILE();
}