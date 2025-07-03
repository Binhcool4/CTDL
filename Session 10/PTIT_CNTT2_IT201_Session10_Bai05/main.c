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

Node* deleteByValue(Node* head, int target) {
    while (head != NULL && head->data == target) {
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    Node* current = head;
    while (current != NULL && current->next != NULL ) {
        if (current->next->data == target) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
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
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        head = addNoteAtLast(head, arr[i]);
    }
    printList(head);
    int number;
    printf("Nhap so muon xoa: ");
    scanf("%d", &number);
    head = deleteByValue(head, number);
    printList(head);
    return 0;
}