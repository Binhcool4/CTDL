#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
}Node;

typedef struct Queue {
    struct Node *front, *rear;
}Queue;

Queue *createQueue() {
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

Node *createNode(value) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->next = NULL;
    return node;
}

int enQueue(Queue *q, int value) {
    Node *newNode = createNode(value);
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int printQueue(Queue *q) {
    Node *temp = q->front;
    printf("queue = {\n front->");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    if (q->rear != NULL) {
        printf("%d->NULL\n", q->rear->data);
    } else {
        printf("NULL\n");
        printf("}\n\n");
    }
}

int peakFront(Queue *q) {
    if (q->front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("%d\n", q->front->data);
    }
}

int main() {
    Queue *q = createQueue();
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
    printQueue(q);
    peakFront(q);
    return 0;
}