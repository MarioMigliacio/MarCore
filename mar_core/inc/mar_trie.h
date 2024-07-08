/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_core_log.h                                                                         */
/* \brief: Provide a trie-tree data structure                                                    */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MAR_TRIE_H
#define MAR_TRIE_H

#include "mar_core_type.h"

/*
 * \brief HashMap Data type represents a key/value combination of any type of data, keyed by string.
 * Syntax typedef struct HashMap HashMap makes the interface Opaque type for the hash map.
 */
typedef struct Trie Trie;

// Function prototypes
Trie* trie_create(void);
void trie_free(Trie* trie);
u8 trie_insert(Trie* trie, const char* word);
u8 trie_search(const Trie* trie, const char* word);
u8 trie_delete(Trie* trie, const char* word);

#endif
