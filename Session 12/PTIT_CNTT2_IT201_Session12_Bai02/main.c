#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
}Node;

Node* append(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next  != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

void printlist(Node* head) {
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        printf("Node %d: %d\n",count + 1, temp->data);
        temp = temp->next;
        count++;
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        head = append(head, arr[i]);
    }
    printlist(head);
    return 0;
}