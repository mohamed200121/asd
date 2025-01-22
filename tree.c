#include <stdio.h>
#include <stdlib.h>

// Define the structure for a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in a binary search tree
struct TreeNode* insertNode(struct TreeNode* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

// Function to search for a node in the tree
struct TreeNode* searchNode(struct TreeNode* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    if (val < root->data) {
        return searchNode(root->left, val);
    }
    return searchNode(root->right, val);
}

// Function to find the height of the tree
int treeHeight(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Function to perform in-order traversal
void inOrderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Function to delete the entire tree
void deleteTree(struct TreeNode* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}

int main() {
    struct TreeNode* root = NULL;

    // Insert nodes
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Traverse the tree
    printf("In-order traversal: ");
    inOrderTraversal(root);
    printf("\n");

    // Search for a node
    int searchVal = 40;
    struct TreeNode* foundNode = searchNode(root, searchVal);
    if (foundNode != NULL) {
        printf("Node with value %d found.\n", searchVal);
    } else {
        printf("Node with value %d not found.\n", searchVal);
    }

    // Find the height of the tree
    printf("Height of the tree: %d\n", treeHeight(root));

    // Delete the tree
    deleteTree(root);
    root = NULL;

    return 0;
}