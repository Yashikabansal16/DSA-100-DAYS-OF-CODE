/*Problem: BST Insert

Implement the solution for this problem.

Input:
- Input specifications

Output:
- Output specifications*/

#include <stdio.h>
#include <stdlib.h>

// Definition of TreeNode
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to insert into BST
struct TreeNode* insertIntoBST(struct TreeNode* root, int val) {
    if (root == NULL) {
        struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        newNode->val = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

// Inorder traversal (to check BST)
void inorder(struct TreeNode* root) {
    if (root == NULL) return;

    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    struct TreeNode* root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter values:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insertIntoBST(root, val);
    }

    printf("Inorder Traversal of BST: ");
    inorder(root);

    return 0;
}