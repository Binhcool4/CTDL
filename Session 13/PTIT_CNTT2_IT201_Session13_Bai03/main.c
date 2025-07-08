#include <stdio.h>
#define MAX 5

typedef struct {
    int stack[MAX];
    int top;
    int capacity;
}Stack;

void initStack(Stack *stack) {
    stack->top = -1;
    stack->capacity = MAX;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void push(Stack *stack, int data) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full\n");
    } else {
        stack->top++;
        stack->stack[stack->top] = data;
    }
}

int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->stack[stack->top--];
}

int main() {
    Stack stack;
    initStack(&stack);
    printf("Pop: %d\n", pop(&stack));
    return 0;
}