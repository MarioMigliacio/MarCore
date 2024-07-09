/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_trie.h                                                                              */
/* \brief: Provide a trie-tree data structure                                                    */
/*                                                                                               */
/* \Expects: mc_trie.h is linked properly and defines interface                                  */
/*                                                                                               */
/* ********************************************************************************************* */

#include "mc_trie.h"
#include <stdlib.h>     // malloc
#include <string.h>     // memset

/**
 * \brief The allowed things to be stored in a Trie are the English Alphabet letters
 */
#define ALPHABET_SIZE 26

/**
 * TODO: 
 * 
 */
typedef struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    u8 isEndOfWord;
} TrieNode;

/**
 * TODO: 
 * 
 */
struct MC_Trie
{
    TrieNode* root;
};

/**
 * TODO: 
 * 
 */
static TrieNode* create_node(void)
{
    TrieNode* node = (TrieNode*)malloc(sizeof(TrieNode));

    if (node)
    {
        memset(node, 0, sizeof(*node));
    }

    return node;
}

MC_Trie* MC_Trie_Init(void)
{
    MC_Trie* trie = (MC_Trie*)malloc(sizeof(MC_Trie));

    if (trie)
    {
        trie->root = create_node();
    }

    return trie;
}

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

void MC_Trie_Free(MC_Trie* trie)
{
    if (trie)
    {
        destroy_node(trie->root);
        free(trie);
    }
}

u8 MC_Trie_Insert(MC_Trie* trie, const char* word)
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

u8 MC_Trie_Search(const MC_Trie* trie, const char* word)
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

u8 MC_Trie_RemoveAt(MC_Trie* trie, const char* word)
{
    if (!trie || !word)
    {
        return FALSE;
    }

    return delete_helper(trie->root, word, 0);
}
