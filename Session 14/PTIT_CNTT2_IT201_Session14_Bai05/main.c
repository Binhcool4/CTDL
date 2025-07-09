#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* push(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Khong du bo nho");
        return head;
    }
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

int peek(Node* head) {
    if (head == NULL) {
        return -1;
    }
    return head->data;
}

void print(Node* head) {
    printf("Stack = { ");
    while (head != NULL) {
        printf("%d-> ", head->data);
        head = head->next;
    }
    printf("NULL }\n");
}

int main() {
    Node* stack = NULL;
    stack = push(stack, 50);
    stack = push(stack, 40);
    stack = push(stack, 30);
    stack = push(stack, 20);
    stack = push(stack, 10);
    print(stack);
    int topValue = peek(stack);
    if (topValue != 1) {
        printf("%d\n", topValue);
    }
    Node* emptyStack = NULL;
    peek(emptyStack);
    return 0;
}