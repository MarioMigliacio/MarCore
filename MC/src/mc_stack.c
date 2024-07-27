/* ********************************************************************************************* */
/*                                                                                               */
/* Author: Mario Migliacio                                                                       */
/* @file: mc_stack.c                                                                             */
/* \brief: Provide a stack-like data structure                                                   */
/*                                                                                               */
/* \Expects: mc_type.h is linked properly and defines types needed                               */
/*                                                                                               */
/* ********************************************************************************************* */

#include <stdlib.h>
#include "mc_stack.h"

typedef struct StackNode
{
    void* data;
    u8 isDynamic;
    struct StackNode* next;
} StackNode;

struct MC_Stack
{
    StackNode* top;
    u64 size;
};

MC_Stack* MC_Stack_Init()
{
    MC_Stack* stack = (MC_Stack*)malloc(sizeof(MC_Stack));

    if (stack)
    {
        stack->top = NULL;
        stack->size = 0;
    }

    return stack;
}

u8 MC_Stack_Push(MC_Stack* stack, void* value, u8 isDynamic)
{
    if (!stack)
    {
        return false;
    }

    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));

    if (!newNode)
    {
        return false;
    }

    newNode->data = value;
    newNode->isDynamic = isDynamic;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->size++;

    return true;
}

void* MC_Stack_Pop(MC_Stack* stack)
{
    if (!stack || !stack->top)
    {
        return NULL;
    }

    StackNode* temp = stack->top;
    void* value = temp->data;
    stack->top = stack->top->next;

    if (temp->isDynamic)
    {
        free(temp->data);
    }

    free(temp);
    stack->size--;

    return value;
}

void* MC_Stack_Peek(const MC_Stack* stack)
{
    if (!stack || !stack->top)
    {
        return NULL;
    }

    return stack->top->data;
}

u8 MC_Stack_IsEmpty(const MC_Stack* stack)
{
    return stack == NULL || stack->top == NULL;
}

u64 MC_Stack_Size(const MC_Stack* stack)
{
    if (!stack)
    {
        return 0;
    }

    return stack->size;
}

void MC_Stack_Free(MC_Stack** stack)
{
    if (!stack || !(*stack))
    {
        return;
    }

    StackNode* current = (*stack)->top;

    while (current)
    {
        StackNode* temp = current;
        current = current->next;

        if (temp->isDynamic)
        {
            free(temp->data);
        }

        free(temp);
    }

    free(*stack);

    *stack = NULL;
}
