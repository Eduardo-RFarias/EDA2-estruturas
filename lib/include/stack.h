#ifndef STACK_H
#define STACK_H

#include <stdlib.h>

typedef struct
{
    int *stack;
    int top;
} Stack;

Stack *stack_init(int size);

void stack_free(Stack *stack);

void stack_push(Stack *stack, int value);

int stack_pop(Stack *stack);

int stack_empty(Stack *stack);

#endif // STACK_H