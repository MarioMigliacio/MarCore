/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_test_module_guid.c                                                                  */
/* \brief: Source code for testing mc_guid                                                       */
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

u32 Test_MC_Guid_Generate(void)
{
    /* Arrange */
    TEST_INIT();
    
    u32 failCount           = 0;
    u16 successGenerates    = 0;
    u16 successReleases     = 0;
    MC_Guid *guid[TEST_CONSTANT_10000];

    /* Act */
    for (u16 i = 0; i < TEST_CONSTANT_10000; i++)
    {
        successGenerates += MC_GUID_Generate(&guid[i]);
    }

    for (u16 i = 0; i < TEST_CONSTANT_10000; i++)
    {
        MC_GUID_Release(&guid[i]);

        if (guid[i] == NULL)
        {
            successReleases++;
        }
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(TEST_CONSTANT_10000, successGenerates, failCount);
    ASSERT_EQUAL_UINT64(successGenerates, successReleases, failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

u32 Test_MC_Guid_Format(void)
{
    /* Arrange */
    TEST_INIT();
    
    u32 failCount           = 0;
    u16 successGenerates    = 0;
    u16 successFormats      = 0;
    u16 successReleases     = 0;
    MC_Guid *guid[TEST_CONSTANT_10000];
    char guid_strs[TEST_CONSTANT_10000][MC_GUID_SIZE];

    /* Act */
    for (u16 i = 0; i < TEST_CONSTANT_10000; i++)
    {
        successGenerates += MC_GUID_Generate(&guid[i]);

        if (successGenerates)
        {
            successFormats += MC_GUID_Format_String(guid[i], guid_strs[i], sizeof(guid_strs[i]));
        }
    }

    for (u16 i = 0; i < TEST_CONSTANT_10000; i++)
    {
        MC_GUID_Release(&guid[i]);

        if (guid[i] == NULL)
        {
            successReleases++;
        }
    }

    /* Assert */
    ASSERT_EQUAL_UINT64(TEST_CONSTANT_10000, successGenerates, failCount);
    ASSERT_EQUAL_UINT64(TEST_CONSTANT_10000, successFormats, failCount);
    ASSERT_EQUAL_UINT64(successGenerates, successReleases, failCount);

    TEST_TEARDOWN(failCount);

    return failCount;
}

int main(void)
{
    int failCount = 0;

    failCount += Test_MC_Guid_Generate();
    failCount += Test_MC_Guid_Format();

    return failCount;
}
