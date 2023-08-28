#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the Binary Search Tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Definition of a stack for iterative traversals
struct StackNode {
    struct TreeNode* node;
    struct StackNode* next;
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

// Function to perform iterative inorder traversal of the binary search tree
void iterativeInorderTraversal(struct TreeNode* root) {
    struct TreeNode* current = root;
    struct StackNode* stack = NULL;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current;
            newNode->next = stack;
            stack = newNode;
            current = current->left;
        }

        current = stack->node;
        stack = stack->next;

        printf("%d ", current->data);

        current = current->right;
    }
}

// Function to perform iterative preorder traversal of the binary search tree
void iterativePreorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct StackNode* stack = NULL;
    struct TreeNode* current = root;

    while (current != NULL || stack != NULL) {
        while (current != NULL) {
            printf("%d ", current->data);

            if (current->right != NULL) {
                struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
                newNode->node = current->right;
                newNode->next = stack;
                stack = newNode;
            }

            current = current->left;
        }

        if (stack != NULL) {
            current = stack->node;
            stack = stack->next;
        }
    }
}

// Function to perform iterative postorder traversal of the binary search tree
void iterativePostorderTraversal(struct TreeNode* root) {
    if (root == NULL) return;

    struct StackNode* stack1 = NULL;
    struct StackNode* stack2 = NULL;
    struct TreeNode* current = root;

    struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    newNode->node = current;
    newNode->next = stack1;
    stack1 = newNode;

    while (stack1 != NULL) {
        current = stack1->node;
        stack1 = stack1->next;
        
        struct StackNode* newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
        newNode->node = current;
        newNode->next = stack2;
        stack2 = newNode;

        if (current->left != NULL) {
            newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current->left;
            newNode->next = stack1;
            stack1 = newNode;
        }

        if (current->right != NULL) {
            newNode = (struct StackNode*)malloc(sizeof(struct StackNode));
            newNode->node = current->right;
            newNode->next = stack1;
            stack1 = newNode;
        }
    }

    while (stack2 != NULL) {
        printf("%d ", stack2->node->data);
        stack2 = stack2->next;
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

    printf("Iterative Inorder Traversal: ");
    iterativeInorderTraversal(root);
    printf("\n");

    printf("Iterative Preorder Traversal: ");
    iterativePreorderTraversal(root);
    printf("\n");

    printf("Iterative Postorder Traversal: ");
    iterativePostorderTraversal(root);
    printf("\n");
    
    return 0;
}


