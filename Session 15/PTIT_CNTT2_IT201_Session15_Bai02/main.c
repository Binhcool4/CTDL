#include <stdio.h>
#define MAX 5

typedef struct {
    int array[MAX];
    int front;
    int rear;
    int capacity;
}Queue;

Queue createQueue() {
    Queue q;
    q.front = 0;
    q.rear = -1;
    q.capacity = MAX;
    return q;
}

void enQueue(Queue* q, int value) {
    if (q->rear == q->capacity - 1) {
        printf("Queue is full\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
}

void printQueue(Queue q) {
    if (q.rear < q.front) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ",q.array[i]);
    }
    printf("\n");
}

int main() {
    Queue q = createQueue();
    int value;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        enQueue(&q, value);
    }
    printQueue(q);
    scanf("%d", &value);
    enQueue(&q, value);
    return 0;
}