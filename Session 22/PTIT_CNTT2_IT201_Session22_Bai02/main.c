#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node *next;
}Node;

Node *createNode(int vertex) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

Node* adjacentNode[100];

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjacentNode[u];
    adjacentNode[u] = newNode;

    Node* newNode1 = createNode(u);
    newNode1->next = adjacentNode[v];
    adjacentNode[v] = newNode1;
}

void printMatrix(int n) {
    for (int i = 0; i < n; i++) {
        Node* temp = adjacentNode[i];
        printf("%d: ",i);
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int n, u, v;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    for (int i = 0; i < 6; i++) {
        printf("Nhap gia tri lien ket: ");
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }
    printf("\n");
    printMatrix(n);

}