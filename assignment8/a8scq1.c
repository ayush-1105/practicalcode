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

// Function to count leaf nodes in the binary tree
int CountLeafNodes(struct Node* node) {
    if (node == NULL) {
        return 0;
    }
    if (node->left == NULL && node->right == NULL) {
        return 1; // This is a leaf node
    }
    // Recursively count leaf nodes in both subtrees
    return CountLeafNodes(node->left) + CountLeafNodes(node->right);
}

// Function to delete a leaf node
struct Node* deleteLeafNode(struct Node* root, int x) {
    if (root == NULL) {
        return NULL;
    }
    // If the current node is a leaf node
    if (root->data == x && root->left == NULL && root->right == NULL) {
        free(root); // Free the memory of the leaf node
        return NULL; // Return NULL to remove the node
    }
    // Recursively delete from left and right subtrees
    root->left = deleteLeafNode(root->left, x);
    root->right = deleteLeafNode(root->right, x);
    return root; // Return the modified tree
}

// Function to perform inorder traversal of the tree
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Driver code
int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");

    int leafCount = CountLeafNodes(root);
    printf("Number of leaf nodes: %d\n", leafCount);

    root = deleteLeafNode(root, 4);
    printf("Inorder traversal after deleting leaf node 4: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
