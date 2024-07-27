/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_guid.h                                                                              */
/* \brief: Provide a guid (Globally unique Identifier) data structure interface                  */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mc_guid.h"
#include <stdio.h>
#include <stdlib.h>
#include <objbase.h>    // CoCreateGuid and GUID
#include <inttypes.h>   // PRIX32 / PRIX16 etc

/**
 * A GUID (Globally Unique Identifier) consists of 16 bytes, and it is typically represented in a specific format:
 * xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx
 */
typedef struct MC_Guid
{
    u32 data1;                  // 4 bytes
    u16 data2;                  // 2 bytes
    u16 data3;                  // 2 bytes
    u8  data4[EIGHT_BYTES];     // 8 bytes
} MC_Guid;

u8 MC_GUID_Generate(MC_Guid **guid)
{
    if (guid == NULL)
    {
        return false;
    }

    GUID new_guid;
    HRESULT result = CoCreateGuid(&new_guid);

    if (result != S_OK)
    {
        return false;
    }

    *guid = (MC_Guid *)malloc(sizeof(MC_Guid));

    if (*guid == NULL)
    {
        return false;
    }

    (*guid)->data1 = new_guid.Data1;
    (*guid)->data2 = new_guid.Data2;
    (*guid)->data3 = new_guid.Data3;

    for (int i = 0; i < EIGHT_BYTES; ++i)
    {
        (*guid)->data4[i] = new_guid.Data4[i];
    }

    return true;
}

void MC_GUID_Release(MC_Guid **guid)
{
    if (guid && *guid)
    {
        free(*guid);
        *guid = NULL;
    }
}

u8 MC_GUID_Format_String(const MC_Guid *guid, char *guid_str, u64 guid_str_size)
{
    if (guid == NULL || guid_str == NULL)
    {
        return false;
    }

    if (guid_str_size != MC_GUID_SIZE)
    {
        return false;
    }

    /**
     * The confusing part is that a GUID is represented by 16 bytes - each byte is a 00 pair in hexidecimal. 
     * 
     * %08 specifies that the output should be zero-padded to 8 digits.
     * PRIX32 is a macro for formatting uint32_t values as uppercase hexadecimal. Corresponds to the first part of the GUID (guid->data1).
     * 
     * %04 specifies that the output should be zero-padded to 4 digits.
     * PRIX16 is a macro for formatting uint16_t values as uppercase hexadecimal. Corresponds to the second part of the GUID (guid->data2).
     * 
     * Similar for (guid->data3) and (guid->data4) for the following 2 %04 specifications.
     * 
     *    [4]    [2]  [2]  [2]      [6]         (data1)      (data2)   (data3)   (data4[0-1]) (data4[2-7])
     * xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx -> 1st 4 bytes - 2 bytes - 2 bytes - 2 bytes - 6 bytes.             This is the GUID standard.
     */

    snprintf(guid_str, guid_str_size,
        "%08" PRIX32 "-%04" PRIX16 "-%04" PRIX16 "-%04" PRIX16 "-%012" PRIX64,
        guid->data1, guid->data2, guid->data3,
        (u16)((guid->data4[0] << 8) | guid->data4[1]),
        ((u64)guid-> data4[2] << 40) |
        ((u64)guid-> data4[3] << 32) |
        ((u64)guid-> data4[4] << 24) |
        ((u64)guid-> data4[5] << 16) |
        ((u64)guid-> data4[6] << 8)  |
        ((u64)guid-> data4[7]));

    return true;
}