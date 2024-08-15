#include<stdio.h>
#include<stdlib.h>
struct Node { 
    int data;
    struct Node *left;
    struct Node *right;
};

int count = 0;
 
struct Node * create() {
    struct Node *p = NULL;
    int val;
    printf("Enter Node Value (-1 for NULL): ");
    scanf("%d", &val);
    if(val == -1) {
        return NULL;
    }
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    printf("Enter Left child Node Value of %d:-\n", val);
    p->left = create();
    printf("Enter Right child Node Value of %d:-\n", val);
    p->right = create();
    return p;
}

int countInternalNodes(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 0;
    else
        return 1 + countInternalNodes(root->left) + countInternalNodes(root->right);
}

void main() {
    struct Node *root = create();
    printf("Number of Internal Nodes: %d", countInternalNodes(root));
}

