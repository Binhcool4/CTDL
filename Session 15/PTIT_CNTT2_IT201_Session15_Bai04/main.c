#include <stdio.h>
#include <stdbool.h>
#define MAX 5

typedef struct {
    int array[MAX];
    int front, rear;
    int capacity;
}Queue;

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = MAX;
}

bool isEmpty(Queue* queue) {
    return queue->rear < queue->front;
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

void enQueue(Queue *queue, int value) {
    if (queue->rear >= queue->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    queue->array[queue->rear] = value;
}

int main() {
    Queue queue;
    initQueue(&queue);
    displayQueue(&queue);
    enQueue(&queue, 1);
    enQueue(&queue, 2);
    enQueue(&queue, 3);
    displayQueue(&queue);
    return 0;
}