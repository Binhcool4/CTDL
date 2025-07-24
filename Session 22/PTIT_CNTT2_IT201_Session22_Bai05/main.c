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

void addEdge(Node** adj, int u, int v) {
    Node* node = createNode(v);
    node->next = adj[u];
    adj[u] = node;
    node = createNode(u);
    node->next = adj[v];
    adj[v] = node;
}

int count(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        temp = temp->next;
        count++;
    }
    return count;
}

int main() {
    int n, v;
    Node* adj[MAX] = {NULL};
    printf("Nhap so dinh va so canh: ");
    scanf("%d %d", &n, &v);
    printf("Nhap cac canh:\n");
    for (int i = 0; i < v; i++) {
        int u, w;
        scanf("%d %d", &u, &w);
        addEdge(adj, u, w);
    }
    int k;
    printf("Nhap dinh k muon kiem tra: ");
    scanf("%d", &k);
    int result = count(adj[k]);
    printf("So dinh ke voi %d laf: %d", k, result);
}