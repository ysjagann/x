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

// Function to perform in-order traversal of the binary search tree
void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
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

    int elementToInsert;
    printf("Element to insert into the tree: ");
    scanf("%d", &elementToInsert);
    root = insert(root, elementToInsert);

    printf("After Insertion: ");
    inorderTraversal(root);
    
    return 0;
}

