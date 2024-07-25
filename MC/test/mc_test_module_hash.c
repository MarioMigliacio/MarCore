/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test_module_hash.c                                                                  */
/* \brief: Source code for testing mc_hash                                                       */
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

void Test_MC_Hash_InitAndFree(void)
{
    /* Arrange */
    MC_HashMap *hashmap = MC_Hashmap_Init(TEST_CONSTANT_32);

    ASSERT_NOT_NULL(hashmap);

    /* Act */
    MC_Hashmap_Free(&hashmap);

    /* Assert */
    ASSERT_NULL(hashmap);
}

void Test_MC_Hash_BigSize(void)
{
    /* Arrange*/
    MC_HashMap *hashmap = MC_Hashmap_Init(TEST_CONSTANT_1000000);
    u64 successfulInserts = 0;
    u64 checkme = 0;

    char key[TEST_CONSTANT_32];
    char value[TEST_CONSTANT_32];
    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(hashmap);

    /* Act */
    for (u64 i = 0; i < TEST_CONSTANT_1000000; i++)
    {
        sprintf_s(temp, sizeof(temp), "Index: %lld", i);
        strncpy_s(key, sizeof(key), temp, sizeof(key) - 1);
        strncpy_s(value, sizeof(value), temp, sizeof(value) - 1);

        successfulInserts += MC_Hashmap_Insert(hashmap, key, value, false);
    }

    /* Assert */
    checkme += ASSERT_EQUAL_UINT64(successfulInserts, TEST_CONSTANT_1000000);

    MC_Hashmap_Free(&hashmap);

    ASSERT_NULL(hashmap);
}

void Test_MC_Hash_DynamicInsertion(void)
{
    /* Arrange */
    MC_HashMap *hashmap = MC_Hashmap_Init(TEST_CONSTANT_32);
    u64 successfulInserts = 0;

    char key[TEST_CONSTANT_32];
    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(hashmap);

    /* Act */
    for (u8 i = 0; i < TEST_CONSTANT_32; i++)
    {
        sprintf_s(temp, sizeof(temp), "Index: %d", i);
        strncpy_s(key, sizeof(key), temp, sizeof(key) - 1);
        char *value = _strdup(temp);

        successfulInserts += MC_Hashmap_Insert(hashmap, key, value, true);
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(successfulInserts, TEST_CONSTANT_32);

    MC_Hashmap_Free(&hashmap);

    ASSERT_NULL(hashmap);
}

void Test_MC_Hash_SearchAndRemove(void)
{
    /* Arrange */
    MC_HashMap *hashmap = MC_Hashmap_Init(TEST_CONSTANT_32);
    u8 successfulInserts = 0;
    u8 successfulRemoves = 0;

    char key[TEST_CONSTANT_32];
    char value[TEST_CONSTANT_32];
    char temp[TEST_CONSTANT_32];

    ASSERT_NOT_NULL(hashmap);

    /* Act */
    /* Assert */
    for (u8 i = 0; i < TEST_CONSTANT_32; i++)
    {
        sprintf_s(temp, sizeof(temp), "Index: %d", i);

        strncpy_s(key, sizeof(key), temp, sizeof(key) - 1);
        strncpy_s(value, sizeof(key), temp, sizeof(key) - 1);

        successfulInserts += MC_Hashmap_Insert(hashmap, key, value, false);
    }

    ASSERT_EQUAL_UINT64(successfulInserts, TEST_CONSTANT_32);

    for (u8 i = 0; i < TEST_CONSTANT_10; i++)
    {
        sprintf_s(temp, sizeof(temp),"Index: %d", i);
        strncpy_s(key, sizeof(key), temp, sizeof(key) - 1);

        successfulRemoves += MC_Hashmap_RemoveAt(hashmap, key);
        void* o = MC_Hashmap_Search(hashmap, key);

        ASSERT_NULL(o);
    }

    ASSERT_TRUE((successfulInserts - successfulRemoves) == (TEST_CONSTANT_32 - TEST_CONSTANT_10));

    MC_Hashmap_Free(&hashmap);

    ASSERT_NULL(hashmap);
}

int main(void)
{
    Test_MC_Hash_InitAndFree();
    Test_MC_Hash_BigSize();
    Test_MC_Hash_DynamicInsertion();
    Test_MC_Hash_SearchAndRemove();

    return 0;
}