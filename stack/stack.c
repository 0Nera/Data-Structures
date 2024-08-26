#include <stdlib.h>

typedef struct {
    int *data;
    int capacity;
    int top;
} stack_t;

stack_t *stack_create(int capacity) {
    stack_t *stack = malloc(sizeof(stack_t));
    stack->data = malloc(capacity * sizeof(int));
    stack->capacity = capacity;
    stack->top = -1;
    return stack;
}

int stack_is_empty(stack_t *stack) {
    return stack->top == -1;
}

int stack_is_full(stack_t *stack) {
    return stack->top == stack->capacity - 1;
}

void stack_push(stack_t *stack, int item) {
    if (stack_is_full(stack)) return;
    stack->data[++stack->top] = item;
}

int stack_pop(stack_t *stack) {
    if (stack_is_empty(stack)) return -1;
    return stack->data[stack->top--];
}

int stack_peek(stack_t *stack) {
    if (stack_is_empty(stack)) return -1;
    return stack->data[stack->top];
}

void stack_free(stack_t *stack) {
    free(stack->data);
    free(stack);
}