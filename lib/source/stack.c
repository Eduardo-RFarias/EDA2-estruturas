#include "stack.h"

Stack *stack_init(int size)
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->stack = (int *)malloc(sizeof(int) * size);
    stack->top = 0;
    return stack;
}

void stack_free(Stack *stack)
{
    free(stack->stack);
    free(stack);
}

void stack_push(Stack *stack, int value)
{
    stack->stack[stack->top++] = value;
}

int stack_pop(Stack *stack)
{
    return stack->stack[--stack->top];
}

int stack_empty(Stack *stack)
{
    return stack->top == 0;
}