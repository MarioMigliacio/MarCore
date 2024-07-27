/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_hash.h                                                                              */
/* \brief: Provide a hash-like data structure                                                    */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_HASH_H
#define MC_HASH_H

#include "mc_type.h"

/**
 * \brief Hint: Use the hashmap_<action> interface to interact with the HashMap pointer.
 * \details HashMap Data type represents a key/value combination of any type of data, keyed by string.
 */
typedef struct MC_HashMap MC_HashMap;

/**
 * \brief Allocates memory for a new HashMap. Initializes the table with NULL pointers and sets the size.
 * \param size: desired size
 * \returns MC_HashMap*: the pointer to a new allocated HashMap.
 */
MC_HashMap* MC_Hashmap_Init(u64 size);

/**
 * \brief Add an element into the HashMap collection. If the Key already exists, update the value.
 * \param map: Pointer to the HashMap to insert into
 * \param key: Null terminated string as Key for key/val pair
 * \param value: Pointer to data as value for key/val pair
 * \param dynamic: true/false, if the value to be inserted was dynamically allocated
 * \returns u8: true/false corresponding to success fail.
 */
u8 MC_Hashmap_Insert(MC_HashMap *map, const char *key, void *value, const u8 dynamic);

/**
 * \brief Look for an existing key/value pair in the HashMap.
 * \param map: Pointer to the HashMap to search from
 * \param key: Null terminated string as Key for key/val pair to search from
 * \returns void*: A pointer to the existing value if key is found, NULL if it doesn't exist.
 */
void* MC_Hashmap_Search(const MC_HashMap *map, const char *key);

/**
 * \brief Remove an element in the HashMap if the key exists.
 * \param map: Pointer to the HashMap to remove from
 * \param key: Null terminated string as Key for key/val pair to be removed
 * \returns u8: true/false corresponding to success fail.
 */
u8 MC_Hashmap_RemoveAt(MC_HashMap *map, const char *key);

/**
 * \brief Free the dynamic memory associated with this HashMap object.
 * \param map: Double Pointer to the HashMap to free, we use a double 
 * pointer indirection so that we can make the map NULL after freeing
 */
void MC_Hashmap_Free(MC_HashMap **map);

/**
 * \brief Print the contents of the hashmap using printf
 * \param map: Pointer to the HashMap to print
 */
void MC_Hashmap_Print(const MC_HashMap *map);

#endif
