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

int isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack *stack, int data) {
    if (isFull(stack)) {
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

void display(int arr[], int size) {
    if (size == 0) {
        printf("Stack is empty\n");
    }
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

int main() {
    Stack stack;
    initStack(&stack);
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < size; i++) {
        push(&stack, arr[i]);
    }
    int arr1[size];
    for (int i = 0; i < size; i++) {
        arr1[i] = pop(&stack);
    }
    display(arr1, size);
    return 0;
}