#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if(newNode == NULL) {
        printf("Memory allocation failed for Node\n");
        return NULL;
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void postOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    postOrder(root);
    return 0;
}