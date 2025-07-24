#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node *next;
}Node;

Node* createNode(int vertex) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

void addLast(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void convert(int n, int matrix[MAX][MAX], Node* adj[]) {
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1) {
                addLast(&adj[i], j);
            }
        }
    }
}

void printAdjList(int n, Node* adj[]) {
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        printf("%d: ", i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];
    Node* adj[MAX];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    convert(n, matrix, adj);
    printAdjList(n, adj);
    for (int i = 0; i < n; i++) {
        Node* temp = adj[i];
        while (temp != NULL) {
            Node* free = temp;
            temp = temp->next;
            free(free);
        }
    }
    return 0;
}