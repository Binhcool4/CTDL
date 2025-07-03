#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

Node* addNoteAtLast(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (head == NULL) {
        return  newNode;
    }
    Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    for (int i = 0; i <= 10; i++) {
        head = addNoteAtLast(head, i);
    }
    printf("Danh sach truoc khi them: ");
    printList(head);
    int value;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &value);
    if (value <= 0) {
        printf("Vui long nhap so nguyen duong");
        return 0;
    }
    head = addNoteAtLast(head, value);
    printf("Danh sach sau khi them: ");
    printList(head);
    return 0;
}