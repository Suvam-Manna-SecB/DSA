#include<stdio.h>
#include<stdlib.h>

struct Node { 
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create() {
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

int totalSiblings(struct Node* root) {
    if (root == NULL)
        return 0;
    
    int leftSiblings = totalSiblings(root->left);
    int rightSiblings = totalSiblings(root->right);

    int siblings = 0;
    if (root->left != NULL && root->right != NULL)
        siblings++;
    
    // Add siblings for the left and right subtrees to the count
    return siblings + leftSiblings + rightSiblings;
}

int main() {
    struct Node *root = create();
    printf("Total Number of Siblings: %d\n", totalSiblings(root));
    return 0;
}
