/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_stack.h                                                                             */
/* \brief: Provide a stack-like data structure                                                   */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#ifndef MC_STACK_H
#define MC_STACK_H

#include "mc_type.h"

/**
 * \brief Hint: Use the stack_<action> interface to interact with the Stack pointer.
 * \details Stack Data type represents any type of data, in first in, last out fashion.
 */
typedef struct MC_Stack MC_Stack;

/**
 * \brief Allocates memory for a new Stack. Initializes the structure with NULL pointer.
 * \returns MC_Stack*: the pointer to a new allocated Stack.
 */
MC_Stack* MC_Stack_Init();

/**
 * \brief Add an element into the Stack collection. If the Key already exists, update the value.
 * \param stack: Pointer to the Stack to push onto
 * \param value: Pointer to data as value
 * \param dynamic: TRUE/FALSE, if the value to be inserted was dynamically allocated
 * \returns u8: TRUE/FALSE corresponding to success fail
 */
u8 MC_Stack_Push(MC_Stack* stack, void* value, u8 dynamic);

/**
 * \brief Remove the top element in the Stack if the Stack is non-empty.
 * \param stack: Pointer to the Stack to remove from
 * \returns void*: A pointer to the existing value if top of stack was popped, NULL otherwise.
 */
void* MC_Stack_Pop(MC_Stack* stack);

/**
 * \brief Look at the top element in the Stack if the Stack is non-empty.
 * \param stack: Pointer to the Stack to peek from
 * \returns void*: A pointer to the existing value of the top of the stack if non-empty, NULL otherwise.
 */
void* MC_Stack_Peek(const MC_Stack* stack);

/**
 * \brief Get the state of whether or not the Stack is Empty or not. 
 * \param stack: Pointer to the Stack to determine if empty
 * \returns u8: State of TRUE/FALSE to Is it empty.
 */
u8 MC_Stack_IsEmpty(const MC_Stack* stack);

/**
 * \brief Get the current size of the Stack.
 * \param stack: Pointer to the Stack to determine the size
 * \returns u64: The stack size.
 */
u64 MC_Stack_Size(const MC_Stack* stack);

/**
 * \brief Free the dynamic memory associated with this Stack object.
 * \param stack: Double Pointer to the Stack to free, we use a double 
 * pointer indirection so that we can make the map NULL after freeing
 */
void MC_Stack_Free(MC_Stack** stack);

#endif
