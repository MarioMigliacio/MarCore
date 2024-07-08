/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_hash.h                                                                             */
/* \brief: Provide a hash-like data structure                                                    */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MAR_HASH_H
#define MAR_HASH_H

#include "mar_core_type.h"

/*
 * \brief Hint: Use the hashmap_<action> interface to interact with the HashMap pointer.
 * \details HashMap Data type represents a key/value combination of any type of data, keyed by string.
 */
typedef struct HashMap HashMap;

/*
 * \brief Allocates memory for a new HashMap. Initializes the table with NULL pointers and sets the size.
 * \param size: desired size.
 */
HashMap* hashmap_init(u64 size);

/*
 * \brief Add an element into the HashMap collection.
 * \param map: Pointer to the HashMap to insert into
 * \param key: Null terminated string as Key for key/val pair
 * \param value: Pointer to data as value for key/val pair
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 hashmap_insert(HashMap *map, const char *key, void *value);

/*
 * \brief Look for an existing key/value pair in the HashMap
 * \param map: Pointer to the HashMap to insert into
 * \param key: Null terminated string as Key for key/val pair
 * \returns void*: A pointer to the existing key/val pair, NULL if it doesn't exist
 */
void* hashmap_lookup(const HashMap *map, const char *key);

/*
 * \brief Remove an element in the HashMap if the key exists
 * \param map: Pointer to the HashMap to insert into
 * \param key: Null terminated string as Key for key/val pair
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 hashmap_remove_at(HashMap *map, const char *key);

/*
 * \brief Free the dynamic memory associated with this HashMap object
 * \param map: Pointer to the HashMap to Free
 */
void hashmap_free(HashMap *map);

#endif // MAR_HASH_H
