#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(node == NULL) {
        printf("Cap nhat khong thanh cong");
        return NULL;
    }
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void preOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
void inOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d ", node->data);
    inOrder(node->right);
}
void postOrder(Node* node) {
    if(node == NULL) {
        return;
    }
    postOrder(node->left);
    postOrder(node->right);
    printf("%d ", node->data);
}
//BFS
typedef struct Queue {
    Node* items[100];
    int front, rear;
}Queue;
void initQueue(Queue* q) {
    q->front = q->rear = 0;
}
int isEmpty(Queue*q) {
    return q->front == q->rear;
}
void enQueue(Queue* q, Node* node) {
    if (q->rear < 100) {
        q->items[q->rear++] = node;
    }
}
Node* deQueue(Queue* q) {
    if (q->front < q->rear) {
        return q->items[q->front++];
    }
    return NULL;
}
void levelOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    Queue q;
    initQueue(&q);
    enQueue(&q, node);
    while(!isEmpty(&q)) {
        Node* node= deQueue(&q);
        printf("%d ", node->data);
        if (node->left!=NULL) {
            enQueue(&q, node->left);
        }
        if (node->right!=NULL) {
            enQueue(&q, node->right);
        }
    }
}

int main(void) {
    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    printf("PreOrder: ");
    preOrder(root);
    printf("\n");
    printf("InOrder: ");
    inOrder(root);
    printf("\n");
    printf("PostOrder: ");
    postOrder(root);
    printf("\n");
    printf("LevelOrder: ");
    levelOrder(root);
    printf("\n");
    return 0;
}