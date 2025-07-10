#include <stdio.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
}Queue;

void initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

void enQueue(Queue* queue, int value) {
    if (queue->rear < MAX - 1) {
        queue->rear++;
        queue->data[queue->rear] = value;
    }
}

int deQueue(Queue* queue) {
    if (queue->front <= queue->rear) {
        return queue->data[queue->front++];
    }
    return -1;
}

bool isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

bool isIncrea(Queue* queue) {
    if (queue->rear - queue->front < 1) {
        return false;
    }
    int prev = deQueue(queue);
    while (!isEmpty(queue)) {
        int curr = deQueue(queue);
        if (curr - prev != 1) {
            return false;
        }
        prev = curr;
    }
    return true;
}

int main() {
    Queue* queue;
    initQueue(&queue);
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enQueue(&queue, x);
    }
    if (isIncrea(&queue)) {
        printf("True");
    } else {
        printf("False");
    }
    return 0;
}