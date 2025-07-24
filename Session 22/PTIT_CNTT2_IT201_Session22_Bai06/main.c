#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node *next;
}Node;

Node* adjList[MAX];
int visited[MAX];

Node* createNode(int vertex) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

void addEdge(int u, int v) {
    Node* newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void DFS(int v) {
    visited[v] = 1;
    printf("%d ", v);
    Node* temp = adjList[v];
    while (temp != NULL) {
        int adjVertex = temp->vertex;
        if (!visited[adjVertex]) {
            DFS(adjVertex);
        }
        temp = temp->next;
    }
}

int main() {
    int n, e;
    printf("Nhap so dinh (n) va so canh (e): ");
    scanf("%d %d", &n, &e);
    for (int i = 0; i < n; i++) {
        adjList[i] = NULL;
        visited[i] = 0;
    }
    printf("Nhap danh sach %d canh:\n", e);
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    int start;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &start);
    printf("Cac dinh duoc duyet theo DFS tu %d: ", start);
    DFS(start);
    printf("\n");
    return 0;
}