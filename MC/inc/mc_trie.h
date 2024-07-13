/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_trie.h                                                                              */
/* \brief: Provide a trie-tree data structure                                                    */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_TRIE_H
#define MC_TRIE_H

#include "mc_type.h"

/**
 * \brief Trie Data type represents a tree of lookup combination of words.
 * Syntax typedef struct Trie makes the interface Opaque type for the trie tree.
 */
typedef struct MC_Trie MC_Trie;

/**
 * \brief Allocates memory for a new Trie. Initializes the structure with malloc.
 */
MC_Trie* MC_Trie_Init(void);

/**
 * \brief Add an element into the Trie collection.
 * \param trie: Pointer to the Trie to insert into
 * \param word: Null terminated string as record to be added
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 MC_Trie_Insert(MC_Trie* trie, const char* word);

/**
 * \brief Look for an existing word in the Trie
 * \param trie: Pointer to the Trie to insert into
 * \param word: Null terminated string as record to search from
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 MC_Trie_Search(const MC_Trie* trie, const char* word);

/**
 * \brief Remove an element in the Trie if the word exists
 * \param trie: Pointer to the Trie to insert into
 * \param word: Null terminated string as record to be removed
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 MC_Trie_RemoveAt(MC_Trie* trie, const char* word);

/**
 * \brief Free the dynamic memory associated with this Trie object
 * \param trie: Pointer to the Trie to Free
 */
void MC_Trie_Free(MC_Trie* trie);

#endif
