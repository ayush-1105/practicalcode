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

// Function to find the minimum element in BST
struct Node* findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to find the maximum element in BST
struct Node* findMax(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL) {
        current = current->right;
    }
    return current;
}

// Function to delete a node in BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        } else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
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

    root = deleteNode(root, 3);
    printf("Inorder traversal after deleting node 3: ");
    inorderTraversal(root);
    printf("\n");

    struct Node* minNode = findMin(root);
    struct Node* maxNode = findMax(root);
    printf("Minimum element in BST: %d\n", minNode->data);
    printf("Maximum element in BST: %d\n", maxNode->data);

    root = mirror(root);
    printf("Inorder traversal of the mirror image of the BST: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
