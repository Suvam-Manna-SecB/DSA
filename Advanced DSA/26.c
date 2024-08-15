#include<stdio.h>
#include<stdlib.h>
#include <time.h>

struct TreeNode { 
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
struct TreeNode * createBinaryTree() {
    struct TreeNode *p = NULL;
    int val;
    printf("Enter Node Value (-1 for NULL): ");
    scanf("%d", &val);
    if(val == -1) {
        return NULL;
    }
    p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    printf("Enter Left child Node Value of %d:-\n", val);
    p->left = createBinaryTree();
    printf("Enter Right child Node Value of %d:-\n", val);
    p->right = createBinaryTree();
    return p;
}

struct TreeNode *createNodeBST(int val) {
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

struct TreeNode *insertNodeBST(struct TreeNode *root, int val) {
    if(root == NULL) {
        return createNodeBST(val);
    } else if(val <= root->data) {
        root->left = insertNodeBST(root->left, val);
    } else {
        root->right = insertNodeBST(root->right, val);
    }
    return root;
}

struct TreeNode * searchBST(struct TreeNode *root, int val) {
    if(root == NULL || root->data == val) return root;
    else if(val <= root->data) {
        return searchBST(root->left, val);
    } else {
        return searchBST(root->right, val);
    }
}

int searchBinaryTree(struct TreeNode *root, int val) {
    if (root == NULL)
        return 0;
    if (root->data == val)
        return 1;
    return searchBinaryTree(root->left, val) || searchBinaryTree(root->right, val);
}

void main() {
    int arr[] = {5,4,6,3,7,2,8,1,9};
    struct TreeNode *rootBinaryTree = createBinaryTree();
    struct TreeNode *rootBST = insertNodeBST(rootBST, arr[0]);
    for(int i = 1; i < 9; i++) {
        insertNodeBST(rootBST, arr[i]);
    }
    clock_t start_BT = clock();
    searchBinaryTree(rootBinaryTree, 9);
    clock_t end_BT = clock();
    double timeTakenBT = ((double)(end_BT - start_BT)) / CLOCKS_PER_SEC;
    clock_t start_BST = clock();
    searchBST(rootBST, 9);
    clock_t end_BST = clock();
    double timeTakenBST = ((double)(end_BST - start_BST)) / CLOCKS_PER_SEC;
    printf("Time Taken For Searching in Binary Tree: %f", timeTakenBT);
    printf("\nTime Taken For Searching in Binary Search Tree: %f", timeTakenBST);
}

