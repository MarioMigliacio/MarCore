#include "mar_core_type.h"
#include "mar_core_test_file.h"
#include "mar_core_test_assert.h"

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
 * \brief Run All Tests runs every module that has defined unit tests.
 */
void Run_All_Tests(void)
{
    /* Safekeeping with global file pointer */
    OPEN_TEST_OUTPUT_FILE();

    /* Add each Run_Test_Module here */
    Test_mar_core_type_UnsignedMaxValuesAreExpected();

    /* Safekeeping with global file pointer */
    CLOSE_TEST_OUTPUT_FILE();
}
