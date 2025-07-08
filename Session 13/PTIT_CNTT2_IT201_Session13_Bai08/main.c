#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100

typedef struct {
    int data[MAX];
    int top;
}Stack;

void initStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, int value) {
    if (s->top < MAX - 1) {
        s->data[++s->top] = value;
    } else {
        printf("Stack is full\n");
    }
}

int pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->data[s->top--];
    } else {
        printf("Stack is empty\n");
        return 0;
    }
}

int postFix(char *e) {
    Stack s;
    initStack(&s);
    for (int i= 0; e[i] != '\0'; i++) {
        char c = e[i];
        if (c == ' ') {
            continue;
        }
        if (isdigit(c)) {
            push(&s, c - '0');
        } else {
            int right = pop(&s);
            int left = pop(&s);
            int result = 0;
            switch (c) {
                case '+': result = left + right; break;
                case '-': result = left - right; break;
                case '*': result = left * right; break;
                case '/': result = left / right; break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
            push(&s, result);
        }
    }
    return pop(&s);
}

int main() {
    char ex[MAX];
    printf("Nhap bieu thuc bat ki: ");
    fgets(ex, MAX, stdin);
    ex[strcspn(ex, "\n")] = 0;
    int result = postFix(ex);
    printf("%d\n", result);
    return 0;
}