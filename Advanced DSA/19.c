#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode *createNode(int val) {
    struct TreeNode* p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    return p;
}

struct TreeNode *insertNode(struct TreeNode *root, int val) {
    struct TreeNode *current = root, *parent = NULL;
    struct TreeNode *p = createNode(val);

    if (root == NULL)
        return p;

    while (current != NULL) {
        parent = current;
        if (val <= current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (val <= parent->data)
        parent->left = p;
    else
        parent->right = p;

    return root;
}

void inOrderTraversal(struct TreeNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
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
    
    printf("INORDER TRAVERSAL :-\n");
    inOrderTraversal(root);
}