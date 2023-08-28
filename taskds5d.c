#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the Binary Search Tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a new element into the binary search tree
struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Function to calculate the height of the tree
int calculateHeight(struct TreeNode* root) {
    if (root == NULL) {
        return -1;
    }
    return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
}

// Function to calculate the depth of the tree
int calculateDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + max(calculateDepth(root->left), calculateDepth(root->right));
}

int main() {
    int numNodes,i;
    printf("No. of nodes: ");
    scanf("%d", &numNodes);

    struct TreeNode* root = NULL;

    printf("Nodes in tree: ");
    for ( i = 0; i < numNodes; i++) {
        int value;
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("Tree elements: ");
    // Displaying the tree elements requires an appropriate traversal (e.g., inorder), which is not specified in the input.

    int height = calculateHeight(root);
    printf("Height of the tree: %d\n", height);

    int depth = calculateDepth(root);
    printf("Depth of the tree: %d\n", depth);

    return 0;
}

