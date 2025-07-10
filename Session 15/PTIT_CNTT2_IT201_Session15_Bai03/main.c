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

void print(bool result) {
    if (result) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

int main() {
    Queue que;
    initQueue(&que);
    print(isEmpty(&que));
    Queue q = {
        .array = {1, 2, 3, 4, 5},
        .front = 1,
        .rear = 2,
        .capacity = 5,
        };
    print(isEmpty(&q));
    return 0;
}
