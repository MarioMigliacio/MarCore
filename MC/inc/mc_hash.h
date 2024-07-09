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
 * \param size: desired size.
 */
MC_HashMap* MC_Hashmap_Init(u64 size);

/**
 * \brief Add an element into the HashMap collection.
 * \param map: Pointer to the HashMap to insert into
 * \param key: Null terminated string as Key for key/val pair
 * \param value: Pointer to data as value for key/val pair
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 MC_Hashmap_Insert(MC_HashMap *map, const char *key, void *value);

/**
 * \brief Look for an existing key/value pair in the HashMap
 * \param map: Pointer to the HashMap to search from
 * \param key: Null terminated string as Key for key/val pair to search from
 * \returns void*: A pointer to the existing key/val pair, NULL if it doesn't exist
 */
void* MC_Hashmap_Search(const MC_HashMap *map, const char *key);

/**
 * \brief Remove an element in the HashMap if the key exists
 * \param map: Pointer to the HashMap to insert into
 * \param key: Null terminated string as Key for key/val pair to be removed
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 MC_Hashmap_RemoveAt(MC_HashMap *map, const char *key);

/**
 * \brief Free the dynamic memory associated with this HashMap object
 * \param map: Pointer to the HashMap to Free
 */
void MC_Hashmap_Free(MC_HashMap *map);

#endif
