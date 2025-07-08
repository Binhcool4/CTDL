#include <stdio.h>
#include <string.h>
#define MAX 100

typedef struct {
    char data[MAX];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char c) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = c;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    }
    return '\0';
}

char peek(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');
}

int isValid(char *expression) {
    Stack s;
    initStack(&s);
    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];
        if (c == '(' || c == '{' || c == '[') {
            push(&s, c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (isEmpty(&s)) {
                return 0;
            }
            if (!isMatchingPair(pop(&s), c)) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expression[MAX];
    printf("Enter expression: ");
    fgets(expression, MAX, stdin);
    expression[strcspn(expression, "\n")] = '\0';
    if (isValid(expression)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    return 0;
}