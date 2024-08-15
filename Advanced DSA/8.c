#include<stdio.h>
#include<stdlib.h>
struct Node { 
    int data;
    struct Node *left;
    struct Node *right;
};
 
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

int height(struct Node *root) {
    if (root == NULL) {
        return 0;
    }
    int Lheight = height(root->left);
    int Rheight = height(root->right);
    if(Lheight > Rheight) {
        return Lheight + 1;
    } else {
        return Rheight + 1;
    }
}

void printLevelOrder(struct Node *root, int level) {
    if(root == NULL) return;
    if(level == 0) {
        printf("%d ", root->data);
    } else {
        printLevelOrder(root->left, level - 1);
        printLevelOrder(root->right, level -1);
    }
}

void levelOrderTraversal(struct Node *root) {
    int h = height(root);
    for(int i = 0; i < h; i++) {
        printLevelOrder(root, i);
        printf("\n");
    }
}

void main() {
    struct Node *root = create();
    levelOrderTraversal(root);
}
