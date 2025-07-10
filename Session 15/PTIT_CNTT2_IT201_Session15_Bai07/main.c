#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100
#define NAME_LENGTH 30

typedef struct {
    char name[MAX][NAME_LENGTH];
    int front;
    int rear;
}Queue;

void initQueue(Queue *queue) {
    queue->front = 0;
    queue->rear = -1;
}

bool isEmpty(Queue *queue) {
    return queue->rear < queue->front;
}

bool isFull(Queue *queue) {
    return queue->rear >= MAX - 1;
}

void enQueue(Queue *queue, char customerName[]) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    queue->rear++;
    strncpy(queue->name[queue->rear], customerName, NAME_LENGTH - 1);
    queue->name[queue->rear][NAME_LENGTH - 1] = '\0';
    printf("Da them %d", customerName);
}

void deQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Danh sach phuc vu: %s\n", queue->name[queue->front]);
    queue->front++;
}

void displayQueue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Danh sach khach cho:\n");
    for (int i = queue->front; i <= queue->rear; i++) {
        printf("%d. %s\n", queue->front+1, queue->name[i]);
    }
}

int main() {
    Queue queue;
    initQueue(&queue);
    int choice;
    char name[NAME_LENGTH];
    do {
        printf("\n--- MENU ---\n");
        printf("1. Them khach vao hang doi\n");
        printf("2. Phuc vu khach hang\n");
        printf("3. Hien thi danh sach khach dang cho\n");
        printf("4. Thoat\n");
        printf("Chon thao tac: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhap ten khach hang: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                enQueue(&queue, name);
                break;
            case 2:
                deQueue(&queue);
                break;
            case 3:
                displayQueue(&queue);
                break;
            case 4:
                printf("Thoat\n");
                break;
            default:
                printf("Lua chon khong hop le\n");
        }
    } while (choice != 4);
    return 0;
}