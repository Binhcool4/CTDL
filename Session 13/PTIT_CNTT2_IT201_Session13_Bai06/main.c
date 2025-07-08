#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char stack[MAX];
    int top;
    int capacity;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->capacity = MAX;
}

int isEmpty(Stack *s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

int isFull(Stack *s) {
    if (s->top == s->capacity - 1) {
        return 1;
    }
    return 0;
}

void push(Stack *s, char data) {
    if (!isFull(s)) {
        s->stack[++s->top] = data;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->stack[s->top--];
    }
    return '\0';
}

int isLetter(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

char toLowerCase(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c + 32;
    }
    return c;
}

int isPalindrome(char *str) {
    Stack s;
    initStack(&s);
    int i = 0;
    while (str[i] != '\0') {
        if (isLetter(str[i])) {
            push(&s, toLowerCase(str[i]));
        }
        i = i + 1;
    }
    i = 0;
    while (str[i] != '\0') {
        if (isLetter(str[i])) {
            char c = pop(&s);
            if (toLowerCase(str[i]) != c) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

int main() {
    char str[] = "hello world";
    if (isPalindrome(str)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}