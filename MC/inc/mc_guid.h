/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_guid.h                                                                              */
/* \brief: Provide a guid (Globally unique Identifier) data structure interface                  */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_GUID_H
#define MC_GUID_H

#include "mc_type.h"

/**
 * \brief Magic constant to represent the number for 8 bytes.
 */
#define EIGHT_BYTES 8

/**
 * \brief Use GUID_SIZE when expecting to call Format_String on a Guid.
 * A Guid c-string consists of 36 characters, plus the null terminator.
 * \details exposed to the MC library
 */
#define MC_GUID_SIZE 37

/**
 * \brief Hint: Use the MC_GUID_<action> interface to interact with the GUID objects.
 * \details GUID Data type represents a globally unique identifier, as a string.
 */
typedef struct MC_Guid MC_Guid;

/**
 * \brief Generate a GUID object that is consistent with the windows standard implementation
 *        This Guid will need to be Released when finished.
 * \param guid: Double Pointer to the MC_Guid type struct that is to be altered
 * \returns u8: true/false corresponding to success fail.
 */
u8 MC_GUID_Generate(MC_Guid **guid);

/**
 * \brief Release/Free the memory of a dynamically allocated MC_Guid.
 * \param guid: Double Pointer to the MC_Guid to release, Set to NULL after function
 */
void MC_GUID_Release(MC_Guid **guid);

/**
 * \brief Format a generated GUID into a typical formatted string xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx.
 * \param guid: Pointer to the MC_Guid to receive a formatted string version of
 * \param guid_str: The saved string that is generated as a result of the GUID_Format_String function
 * \param guid_str_size: The size of the string that the guid represents
 * \returns u8: true/false corresponding to success fail.
 */
u8 MC_GUID_Format_String(const MC_Guid *guid, char *guid_str, u64 guid_str_size);


#endif
