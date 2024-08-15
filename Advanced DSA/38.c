#include<stdio.h>
#include<stdlib.h>
struct Node {
   int data;
   struct Node *next;
};

struct Node *top = NULL;

void push(int val) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->next = top;
    top = p;
}

int pop() {
    if(top == NULL) {
        printf("\nSTACK UNDERFLOW");
        return -1;
    }
    int val = top->data;
    struct Node *p = top;
    top = top->next;
    free(p);
    return val;
}

int peek() {
    if(top == NULL) {
        printf("\nSTACK EMPTY");
        return -1;
    }
    return top->data;
}

void display() {
    if(top == NULL) {
        printf("\nEMPTY");
    }
    struct Node *move = top;
    printf("\nSTACK :-\n");
    while(move != NULL) {
        printf("%d\n", move->data);
        move = move->next;
    }
}

void main() {
    int ch, val;
    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                printf("\nEnter Value: ");
                scanf("%d", &val);
                push(val);
                break;
            }
            case 2: {
                val = pop();
                if(val != -1) {
                    printf("\nDeleted Value: %d", val);
                }
                break;
            }
            case 3: {
                printf("Top Element: %d", peek());
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                printf("\nProgram Terminated Successfully.");
                break;
            }
            default: {
                printf("\nInvalid Choice.");
            }
        }
    } while(ch != 5);
}

