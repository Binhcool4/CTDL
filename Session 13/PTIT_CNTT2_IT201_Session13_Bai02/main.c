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

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->top++;
    stack->stack[stack->top] = value;
}

void printStack(Stack *stack) {
    printf("stack={\n element:[");
    for (int i = 0; i < stack->top; i++) {
        printf("%d", stack->stack[i]);
        if (i != stack->top) {
            printf(", ");
        }
    }
    printf("], \n top: %d,\n cap: %d\n}", stack->top, stack->capacity);
}

int main() {
    Stack stack;
    initStack(&stack);
    int value;
    for (int i = 0; i < MAX; i++) {
        printf("Nhap phan tu %d: ", i + 1);
        scanf("%d", &value);
        push(&stack, value);
    }
    printStack(&stack);
}