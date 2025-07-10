#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[30];
    int age;
}Customer;

typedef struct {
    Customer data[MAX];
    int front;
    int rear;
}Queue;

int initQueue(Queue* queue) {
    queue->front = 0;
    queue->rear = -1;
}

int isEmpty(Queue* queue) {
    return queue->front > queue->rear;
}

void enQueue(Queue* queue, Customer c) {
    if (queue->rear < MAX - 1) {
        queue->rear++;
        queue->data[queue->rear] = c;
    } else {
        printf("Queue is full\n");
    }
}

Customer deQueue(Queue* queue) {
    Customer dummy = {"", -1};
    if (!isEmpty(queue)) {
        return queue->data[queue->front++];
    } else {
        printf("Queue is empty\n");
        return dummy;
    }
}

void printQueue(Queue queue, const char* title) {
    printf("%s:\n", title);
    if (isEmpty(&queue)) {
        printf("(empty)\n");
    } else {
        for (int i = queue.front; i < queue.rear; i++) {
            printf("%s (%d year old)\n", queue.data[i].name, queue.data[i].age);
        }
    }
}

int main(void) {
    Queue queueOld, queueNormal;
    initQueue(&queueOld);
    initQueue(&queueNormal);

    int choice;
    do {
        printf("1. Add customers\n");
        printf("2. Serving customers\n");
        printf("3. Show waiting list\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice) {
            
                case 1: {
                    Customer c;
                    printf("Name: ");
                    fgets(c.name, sizeof(c.name), stdin);
                    c.name[strcspn(c.name, "\n")] = 0;
                    printf("Age: ");
                    scanf("%d", &c.age);
                    getchar();
                    if (c.age >= 60) {
                        enQueue(&queueOld, c);
                    } else {
                        enQueue(&queueNormal, c);
                    }
                    break;
                }
                case 2: {
                    if (!isEmpty(&queueOld)) {
                        Customer served = deQueue(&queueOld);
                        printf("In service: %s (%d year old) [prioritize]\n", served.name, served.age);
                    } else if (!isEmpty(&queueNormal)) {
                        Customer served = deQueue(&queueNormal);
                        printf("In service: %s (%d year old)\n", served.name, served.age);
                    } else {
                        printf("There are no customers waiting!\n");
                    }
                    break;
                }
                case 3:
                    printQueue(queueOld, "Priority queue (>=60 years old)");
                    printQueue(queueNormal, "Regular queue (<60 years old)");
                    break;
                case 0:
                    printf("Exit.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }

    } while (choice != 0);
    return 0;
}