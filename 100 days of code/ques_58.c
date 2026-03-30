/*Problem Statement:
Construct a binary tree from given preorder and inorder traversal arrays.

Input Format:
- First line contains integer N
- Second line contains preorder traversal
- Third line contains inorder traversal

Output Format:
- Print postorder traversal of constructed tree

Example:
Input:
5
1 2 4 5 3
4 2 5 1 3

Output:
4 5 2 3 1*/

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

// function to create new node
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// search element in inorder
int search(int inorder[], int start, int end, int value) {
    for(int i = start; i <= end; i++) {
        if(inorder[i] == value)
            return i;
    }
    return -1;
}

// build tree
struct node* buildTree(int preorder[], int inorder[], int start, int end, int *preIndex) {
    if(start > end)
        return NULL;

    // pick current root from preorder
    struct node* root = newNode(preorder[*preIndex]);
    (*preIndex)++;

    // if only one node
    if(start == end)
        return root;

    // find index in inorder
    int inIndex = search(inorder, start, end, root->data);

    // build left and right subtree
    root->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    root->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);

    return root;
}

// postorder traversal
void postorder(struct node* root) {
    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// main function
int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for(int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for(int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    int preIndex = 0;

    struct node* root = buildTree(preorder, inorder, 0, n-1, &preIndex);

    postorder(root);

    return 0;
}