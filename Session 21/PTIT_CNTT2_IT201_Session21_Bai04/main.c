#include <stdio.h>

void addEdge(int graph[3][3], int nodel, int nodeh) {
    graph[nodel][nodeh] = 1;
}

void printGraph(int graph[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int graph[3][3] = {0};
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    printGraph(graph);
    return 0;
}