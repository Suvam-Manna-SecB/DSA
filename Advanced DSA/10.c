#include<stdio.h>
int binaryTree[100];
int idx = -1;
void insert(int val) {
    idx++;
    binaryTree[idx] = val;
} 

void levelOrderTraversal(int n) {
    int p = 1;
    int flag = 0;
    for(int i = 0; i < n; i++) {
        printf("%d", binaryTree[i]);
        flag++;
        if(flag == p) {
            printf("\n");
            flag = 0;
            p *= 2;
        }
        
    }
}

void main() {
    int n, val;
    printf("Enter Number of Nodes(MAX 100): ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        printf("Enter Node Value: ");
        scanf("%d", &val);
        insert(val);
    }
    levelOrderTraversal(n);
}