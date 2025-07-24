#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Node {
    int vertex;
    struct Node *next;
}Node;

Node* adj[MAX];
int visited[MAX];
int queue[MAX];
int front = 0, rear = 0;

void enqueue(int vertex) {
    queue[rear++] = vertex;
}

int dequeue() {
    return queue[front++];
}

int isEmpty() {
    return front == rear;
}

Node* createNode(int vertex) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->vertex = vertex;
    node->next = NULL;
    return node;
}

Node* addEdge(int u, int v) {
    Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
    Node* node1 = createNode(u);
    node1->next = adj[v];
    adj[v] = node1;
}

void BFS(int s) {
    visited[s] = 1;
    enqueue(s);
    while (!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        for (Node* node = adj[u]; node != NULL; node = node->next) {
            int v = node->vertex;
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(v);
            }
        }
    }
}

int main() {
    int v, e;
    printf("Nhap dinh va canh: ");
    scanf("%d %d", &v, &e);
    for (int i = 0; i < v; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }
    printf("Nhap %d canh:\n", e);
    for (int i = 0; i < e; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(u, w);
    }
    int start;
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &start);
    printf("Thu tu duyet BFS: ");
    BFS(start);
    return 0;
}