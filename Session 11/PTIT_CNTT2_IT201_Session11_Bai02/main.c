#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

Node* printList(Node* head) {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf("Node %d: %d\n", count, current->data);
        current = current->next;
        count++;
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 1; i <= 5; i++) {
        Node* node = createNode(i);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }
    }
    printList(head);
    return 0;
}