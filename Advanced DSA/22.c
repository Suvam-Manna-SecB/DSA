#include<stdio.h>
#include<stdlib.h>
struct TreeNode {
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(char val) {
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    p->left = p->right = NULL;
    return p;
}

struct TreeNode *insertNode(struct TreeNode *root, char val) {
    if(root == NULL) {
        return createNode(val);
    } else if(val <= root->data) {
        root->left = insertNode(root->left, val);
    } else {
        root->right = insertNode(root->right, val);
    }
    return root;
}

struct TreeNode * search(struct TreeNode *root, char val) {
    if(root == NULL || root->data == val) return root;
    else if(val <= root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

void inOrderTraversal(struct TreeNode *root) {
    if(root == NULL) return;
    inOrderTraversal(root->left);
    printf("%c ", root->data);
    inOrderTraversal(root->right);
}


void main() {
    int n, val;
    struct TreeNode *root = NULL;
    char name[50];
    printf("Enter Name: ");
    gets(name);
    for(int i = 0; name[i] != '\0'; i++) {
        if(name[i] == ' ') continue;
        if(name[i] < 97) {
            name[i] = name[i] + 32;
        }
        if(i == 0)
            root = insertNode(root, name[i]);
        else
            insertNode(root, name[i]);
    }
    inOrderTraversal(root);
}
