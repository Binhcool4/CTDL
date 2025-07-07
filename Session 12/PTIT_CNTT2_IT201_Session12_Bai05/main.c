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
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteSpecific(Node* head, int value) {
    if (head == NULL) {
        return NULL;
    }
    Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            Node* toDelete = current;
            if (current->prev != NULL) {
                current->prev->next = current->next;
            } else {
                head = current->next;
            }
            if (current->next != NULL) {
                current->next->prev = current->prev;
            }
            current = current->next;
            free(toDelete);
        } else {
            current = current->next;
        }
    }
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int arr[] ={1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* head = NULL;
    for (int i = 0; i < n; i++) {
        head = append(head, arr[i]);
    }
    printList(head);
    int number;
    printf("Nhap so muon xoa: ");
    scanf("%d", &number);
    head = deleteSpecific(head, number);
    printList(head);
    return 0;
}