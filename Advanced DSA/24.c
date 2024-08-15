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

void preOrderTraversal(struct TreeNode *root) {
    if(root == NULL) return;
    printf("%d ", root->data);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(struct TreeNode *root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d ", root->data);
    inOrderTraversal(root->right);
}

void postOrderTraversal(struct TreeNode *root) {
    if(root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d ", root->data);
}

void main() {
    int n, val;
    struct TreeNode *root = NULL;
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter Node Value: ");
        scanf("%d", &val);
        if(i == 0)
            root = insertNode(root, val);
        else
            insertNode(root, val);
    }
    
    printf("\nPREORDER TRAVERSAL :-\n");
    preOrderTraversal(root);
    
    printf("\nINORDER TRAVERSAL :-\n");
    inOrderTraversal(root);
    
    printf("\nPOSTORDER TRAVERSAL :-\n");
    postOrderTraversal(root);
}
