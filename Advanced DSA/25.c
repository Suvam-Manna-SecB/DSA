#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(int val) {
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

struct TreeNode *insertNode(struct TreeNode *root, int val) {
    if(root == NULL) {
        return createNode(val);
    } else if(val <= root->data) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

int countNodes(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findHighestElement(struct TreeNode* root) {
    if (root == NULL)
        return -1;
    while (root->right != NULL)
        root = root->right;
    return root->data;
}

void main() {
    int arr[5] = {30,20,10,40,50}, val;
    struct TreeNode *root = NULL;
    root = insertNode(root, arr[0]);
    for(int i = 1; i < 5; i++) {
        insertNode(root, arr[i]);
    }
    printf("Number of Nodes: %d", countNodes(root));
    printf("\nHighest Element: %d", findHighestElement(root));
}
