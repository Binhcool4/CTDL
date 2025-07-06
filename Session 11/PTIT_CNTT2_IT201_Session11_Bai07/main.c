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
    while (temp-> next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* insert(Node* head, int value, int position) {
    if (position < 1) {
        printf("Vi tri khong hop le");
        return head;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (position == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    Node* temp = head;
    int current = 1;
    while (temp != NULL && current < position) {
        temp = temp->next;
        current++;
    }
    if (temp == NULL) {
        printf("Vi tri khong hop le");
        free(newNode);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

void printList(Node* head) {
    if (head == NULL) {
        printf("Danh sach rong");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    head = append(head, 1);
    head = append(head, 2);
    head = append(head, 3);
    head = append(head, 4);
    head = append(head, 5);
    printList(head);
    int number, position;
    printf("Nhap gia tri muon them: ");
    scanf("%d", &number);
    printf("Nhap vi tri muon them: ");
    scanf("%d", &position);
    head = insert(head, number, position);
    printList(head);
    return 0;
}