#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* push(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(!newNode) {
        printf("Khong du bo nho");
        return head;
    }
    newNode->data = value;
    newNode->next = head;
    return  newNode;
}

int isEmpty(Node* head) {
    return head == NULL;
}

void printStack(Node* head) {
    if(isEmpty(head)) {
        printf("Stack is empty\n");
        return;
    }
    Node* current = head;
    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    Node* stack = NULL;
    stack = push(stack, 10);
    stack = push(stack, 20);
    stack = push(stack, 30);
    stack = push(stack, 40);
    stack = push(stack, 50);
    printStack(stack);
    return 0;
}