#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in BST
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

// Function to count leaf nodes
int countLeafNodes(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

// Function to delete a leaf node
struct Node* deleteLeafNode(struct Node* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == x && root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    root->left = deleteLeafNode(root->left, x);
    root->right = deleteLeafNode(root->right, x);
    return root;
}

// Function to find the minimum element in BST
int findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current->data;
}

// Function to find the maximum element in BST
int findMax(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current->data;
}

// Function to obtain the mirror image of the BST
struct Node* mirror(struct Node* node) {
    if (node == NULL) {
        return NULL;
    }
    struct Node* temp = node->left;
    node->left = mirror(node->right);
    node->right = mirror(temp);
    return node;
}

// Function for inorder traversal
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Driver code
int main() {
    struct Node* root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 8);
    insert(root, 1);
    insert(root, 4);
    insert(root, 7);
    insert(root, 9);

    printf("Inorder traversal of the original BST: ");
    inorderTraversal(root);
    printf("\n");

    printf("Count of leaf nodes: %d\n", countLeafNodes(root));

    root = deleteLeafNode(root, 1);
    printf("Inorder traversal after deleting leaf node 1: ");
    inorderTraversal(root);
    printf("\n");

    printf("Minimum element in BST: %d\n", findMin(root));
    printf("Maximum element in BST: %d\n", findMax(root));

    root = mirror(root);
    printf("Inorder traversal of the mirror image of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
