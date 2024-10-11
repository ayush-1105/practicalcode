#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insert(node->left, data);
    } else {
        node->right = insert(node->right, data);
    }
    return node;
}

int count(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + count(root->left) + count(root->right);
}

void create(struct Node** root, int n, int random) {
    for (int i = 0; i < n; i++) {
        int value;
        if (random) {
            value = rand() % 100; // Random number between 0 and 99
        } else {
            printf("Enter value for node %d: ", i + 1);
            scanf("%d", &value);
        }
        *root = insert(*root, value);
    }
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int n, choice;

    printf("Enter the number of nodes to insert: ");
    scanf("%d", &n);
    
    printf("Enter 1 for random values or 0 for user input: ");
    scanf("%d", &choice);
    
    srand(time(NULL));
    create(&root, n, choice);
    
    printf("Inorder traversal of the BST: ");
    inorderTraversal(root);
    printf("\n");

    int nodeCount = count(root);
    printf("Total number of nodes in the BST: %d\n", nodeCount);

    return 0;
}
