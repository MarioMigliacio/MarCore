/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mar_core_log.h                                                                         */
/* \brief: Provide a trie-tree data structure                                                    */
/*                                                                                               */
/* \Expects: No expectations are made prior to type definitions in this file                     */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mar_trie.h"
#include <stdlib.h>     // malloc
#include <string.h>     // memset

#define ALPHABET_SIZE 26

// Definition of the trie node structure
typedef struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    u8 isEndOfWord;
} TrieNode;

// Definition of the trie structure
struct Trie
{
    TrieNode* root;
};

// Utility function to create a new trie node
static TrieNode* create_node(void)
{
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    if (node)
    {
        memset(node, 0, sizeof(*node));
    }

    return node;
}

// Create a new trie
Trie* trie_create(void)
{
    Trie* trie = (Trie*)malloc(sizeof(Trie));

    if (trie)
    {
        trie->root = create_node();
    }

    return trie;
}

// Recursively free all nodes in the trie
static void destroy_node(TrieNode* node)
{
    if (node)
    {
        for (int i = 0; i < ALPHABET_SIZE; i++)
        {
            destroy_node(node->children[i]);
        }

        free(node);
    }
}

// Destroy the trie
void trie_free(Trie* trie)
{
    if (trie)
    {
        destroy_node(trie->root);
        free(trie);
    }
}

// Insert a word into the trie
u8 trie_insert(Trie* trie, const char* word)
{
    if (!trie || !word)
    {
        return FALSE;
    }

    TrieNode* node = trie->root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';
        
        if (index < 0 || index >= ALPHABET_SIZE)
        {
            return FALSE;  // Invalid character
        }

        if (!node->children[index])
        {
            node->children[index] = create_node();

            if (!node->children[index])
            {
                return FALSE;  // Memory allocation failure
            }
        }

        node = node->children[index];
    }

    node->isEndOfWord = TRUE;

    return TRUE;
}

// Search for a word in the trie
u8 trie_search(const Trie* trie, const char* word)
{
    if (!trie || !word)
    {
        return FALSE;
    }

    TrieNode* node = trie->root;

    for (int i = 0; word[i] != '\0'; i++)
    {
        int index = word[i] - 'a';

        if (index < 0 || index >= ALPHABET_SIZE || !node->children[index])
        {
            return FALSE;
        }

        node = node->children[index];
    }

    return node->isEndOfWord;
}

// Recursive helper to delete a word from the trie
static u8 delete_helper(TrieNode* node, const char* word, int depth)
{
    if (!node)
    {
        return FALSE;
    }

    if (word[depth] == '\0')
    {
        if (node->isEndOfWord)
        {
            node->isEndOfWord = FALSE;

            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (node->children[i])
                {
                    return FALSE;
                }
            }

            return TRUE;
        }

        return FALSE;
    }

    int index = word[depth] - 'a';

    if (delete_helper(node->children[index], word, depth + 1))
    {
        free(node->children[index]);
        node->children[index] = NULL;

        if (!node->isEndOfWord)
        {
            for (int i = 0; i < ALPHABET_SIZE; i++)
            {
                if (node->children[i])
                {
                    return FALSE;
                }
            }

            return TRUE;
        }
    }

    return FALSE;
}

// Delete a word from the trie
u8 trie_delete(Trie* trie, const char* word)
{
    if (!trie || !word)
    {
        return FALSE;
    }

    return delete_helper(trie->root, word, 0);
}
