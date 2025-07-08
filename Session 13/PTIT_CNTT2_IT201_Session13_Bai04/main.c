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
    }else {
        stack->top++;
        stack->stack[stack->top] = data;
    }
}

void display(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return;
    }
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->stack[i]);
    }
}

int main() {
    Stack stack;
    initStack(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);
    display(&stack);
    return 0;
}