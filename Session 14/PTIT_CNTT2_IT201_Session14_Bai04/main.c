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
    return newNode;
}

Node* pop(Node* head, int* value) {
    if(head == NULL) {
        printf("Stack is empty");
        *value = -1;
        return NULL;
    }
    *value = head->data;
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void print(Node* head) {
    Node* current = head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    head = push(head, 50);
    head = push(head, 40);
    head = push(head, 30);
    head = push(head, 20);
    head = push(head, 10);
    print(head);
    int value;
    head = pop(head, &value);
    if (value != -1) {
        printf("%d\n", value);
    }
    print(head);
}