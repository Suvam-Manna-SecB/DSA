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

void inOrderTraversal(struct TreeNode *root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void main() {
    int val;
    int arr[5] = {30, 10, 20, 40, 50};
    struct TreeNode *root = NULL;
    for(int i = 0; i < 5; i++) {
        if(i == 0)
            root = insertNode(root, arr[i]);
        else
            insertNode(root, arr[i]);
    }
    
    printf("EXISTING BINARY SEARCH TREE :-\n");
    inOrderTraversal(root);
    
    printf("\nEnter Node Value: ");
    scanf("%d", &val);
    
    insertNode(root, val);
    
    printf("BINARY SEARCH TREE AFTER ADDING %d :-\n", val);
    inOrderTraversal(root);
}
