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

int treeHeight(Node* root) {
    if (root == NULL) {
        return -1;
    }

    int left = treeHeight(root->left);
    int right = treeHeight(root->right);

    if (left > right) {
        return left + 1;
    }else {
        return right + 1;
    }
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int height = treeHeight(root);
    printf("%d", height);
    return 0;
}