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

bool isEmpty(Queue *queue) {
    return queue->rear < queue->front;
}

int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int value = queue->array[queue->front];
    queue->front++;
    return value;
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is full\n");
        return;
    }
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}

void enqueue(Queue *queue, int value) {
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
    dequeue(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 5);
    displayQueue(&queue);
    int j = dequeue(&queue);
    printf("return value = %d\n", j);
    displayQueue(&queue);
    return 0;
}