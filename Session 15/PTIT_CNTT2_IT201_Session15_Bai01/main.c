#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* array;
    int front;
    int rear;
    int capacity;
}Queue;

Queue* createQueue(int maxSize) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->array = (int*)malloc(maxSize * sizeof(int));
    q->front = 0;
    q->rear = -1;
    q->capacity = maxSize;
    return q;
}

int main() {
    Queue* q = createQueue(5);
    printf("front = %d, near = %d, capacity = %d\n", q->front, q->rear, q->capacity);
    free(q);
    return 0;
}