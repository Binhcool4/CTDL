#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *right;
    struct Node *left;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Cap phat khong thanh cong");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

typedef struct QueueNode {
    Node* treeNode;
    struct QueueNode* next;
}QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
}Queue;

void initQueue(Queue* queue) {
    queue->front = queue->rear = NULL;
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void enQueue(Queue* queue, Node* treeNode) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

Node* deQueue(Queue* queue) {
    if (isEmpty(queue)) {
        return NULL;
    }
    QueueNode* temp = queue->front;
    Node* treeNode = temp->treeNode;
    queue->front = queue->front->next;
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    free(temp);
    return treeNode;
}

int BFS(Queue* root, int value) {
    if (root == NULL) {
        return 0;
    }
    Queue q;
    initQueue(&q);
    enQueue(&q, root);
    while (!isEmpty(&q)) {
        Node* current = deQueue(&q);
        if (current->data == value) {
            return 1;
        }
        if (current->left != NULL) {
            enQueue(&q, current->left);
        }
        if (current->right != NULL) {
            enQueue(&q, current->right);
        }
    }
    return 0;
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int n;
    scanf("%d", &n);
    int result = BFS(root, n);
    if (result) {
        printf("true");
    } else {
        printf("false");
    }
    return 0;
}