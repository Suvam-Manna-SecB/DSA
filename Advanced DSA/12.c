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

int nodeDegree(struct Node* root, int target) {
    if (root == NULL)
        return -1;
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front < rear) {
        struct Node* current = queue[front++];
        if (current->data == target) {
            int degree = 0;
            if (current->left != NULL) degree++;
            if (current->right != NULL) degree++;
            return degree;
        }
        if (current->left != NULL)
            queue[rear++] = current->left;
        if (current->right != NULL)
            queue[rear++] = current->right;
    }
    return -1;
}


void main() {
    int n;
    struct Node *root = create();
    printf("Enter Node For Finding Degree: ");
    scanf("%d", &n);
    printf("Degree of %d : %d", n, nodeDegree(root, n));
}
