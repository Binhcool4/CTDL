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

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int DPS(Node* root, int value) {
    if(root == NULL) {
        return 0;
    }
    if(root->data == value) {
        return 1;
    }
    int foundLeft = DPS(root->left, value);
    if(foundLeft) {
        return DPS(root->right, value);
    }
}

int main() {
    Node* root = createNode(2);
    root->left = createNode(3);
    root->right = createNode(4);
    root->left->left = createNode(5);
    int n;
    scanf("%d", &n);
    int result = DPS(root, n);
    if(result == 1) {
        printf("True\n");
    } else {
        printf("False\n");
    }
    return 0;
}