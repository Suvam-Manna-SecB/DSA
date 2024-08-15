#include<stdio.h>
#include<stdlib.h>
struct Node {
   int data;
   struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void enqueue(int val) {
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

int dequeue() {
    if(front == NULL) {
        printf("\nQUEUE UNDERFLOW");
        return -1;
    }
    int val = front->data;
    struct Node *p = front;
    front = front->next;
    free(p);
    return val;
}

int peek() {
    if(front == NULL) {
        printf("\nQUEUE EMPTY");
        return -1;
    }
    return front->data;
}

void display() {
    if(front == NULL) {
        printf("\nEMPTY");
    }
    struct Node *move = front;
    printf("\nQUEUE :-\n");
    while(move != NULL) {
        printf("%d ", move->data);
        move = move->next;
    }
}

void main() {
    int ch, val;
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                printf("\nEnter Value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            }
            case 2: {
                val = dequeue();
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

