#include<stdio.h>
#include<stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Node {
   struct TreeNode *data;
   struct Node *next;
};

struct TreeNode *root = NULL;
struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(struct TreeNode *val) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->next = NULL;
    if(front == NULL) {
        front = p;
        rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
    
}

struct TreeNode * dequeue() {
    if(front == NULL) {
        return NULL;
    }
    struct TreeNode *val = front->data;
    struct Node *p = front;
    front = front->next;
    free(p);
    return val;
}

int isEmpty() {
    if(front == NULL) return 1;
    else return 0;
}

void queueReset() {
    front = NULL;
    rear = NULL;
}

void insert(int val) {
    struct TreeNode *p = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    p->data = val;
    p->left = NULL;
    p->right = NULL;
    if(root == NULL) {
        root = p;
    } else {
        enqueue(root);
        while(!isEmpty()) {
            struct TreeNode *current = dequeue();
            if(current->left == NULL) {
                current->left = p;
                break;
            } else {
                enqueue(current->left);
            }
            if(current->right == NULL) {
                current->right = p;
                break;
            } else {
                enqueue(current->right);
            }
        }
    }
}

int isPowerOfTwo(int num) {
    return (num && !(num & (num - 1)));
}

void levelOrderTraversal() {
    if(root == NULL) return;
    queueReset();
    enqueue(root);
    int flag = 1;
    while(!isEmpty()) {
        struct TreeNode *temp = dequeue();
        printf("%d ", temp->data);
        flag++;
        if(isPowerOfTwo(flag)) {
            printf("\n");
        }
        if (temp->left != NULL) {
            enqueue(temp->left);
        }
        if (temp->right != NULL) {
            enqueue(temp->right);
        }
    }
}

void main() {
    int val;
    while(1){
        printf("Enter Node Value(-1 For No More Insertion): ");
        scanf("%d", &val);
        if(val == -1) break;
        insert(val);
    }

    levelOrderTraversal();
}



