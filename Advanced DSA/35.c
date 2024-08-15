#include<stdio.h>
#include<stdlib.h>
struct Node {
   int data;
   struct Node *next;
};

struct Node *head = NULL;

void insertBeginning(int val) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->next = head;
    head = p;
}

void insertEnd(int val) {
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    p->next = NULL;
    struct Node *move = head;
    while(move->next != NULL) {
        move = move->next;
    }
    move->next = p;
}

void insertPosition(int position, int val) {
    if(position == 1) {
        insertBeginning(val);
        return;
    }
    struct Node *p = (struct Node *)malloc(sizeof(struct Node));
    p->data = val;
    struct Node *move1 = head;
    struct Node *move2 = NULL;
    while(position - 1 > 1) {
        move1 = move1->next;
        position--;
    }
    move2 = move1->next;
    move1->next = p;
    p->next = move2;
}

void deleteBeginning() {
    struct Node *p = head;
    head = head->next;
    free(p);
}

void deleteEnd() {
    if(head->next == NULL) {
        deleteBeginning();
        return;
    }
    struct Node *move = head;
    while(move->next->next != NULL) {
        move = move->next;
    }
    struct Node *p = move->next;
    move->next = NULL;
    free(p);
}

void deletePosition(int position) {
    if(head->next == NULL) {
        deleteBeginning();
        return;
    }
    struct Node *move1 = head;
    while(position - 1 > 1) {
        move1 = move1->next;
        position--;
    }
    struct Node *move2 = move1->next->next;
    struct Node *p = move1->next;
    move1->next = move2;
    free(p);
}

int count() {
    int c = 0;
    struct Node *move = head;
    while(move != NULL) {
        c++;
        move = move->next;
    }
    return c;
}

void display() {
    if(head == NULL) {
        printf("\nEmpty");
        return;
    }
    struct Node *move = head;
    while(move != NULL) {
        printf("%d -> ", move->data);
        move = move->next;
    }
    printf("NULL");
}

void reverse() {
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *next = head->next;
    while(curr != NULL) {
        curr->next = prev;
        prev = curr;
        curr = next;
        if(next != NULL) {
            next = next->next;
        } 
    }
    head = prev;
}

void main() {
    int ch, val, pos;
    do {
        printf("\n1.Insert At Beginning\n2.Insert At End\n3.Insert At Position\n4.Delete From Beginning\n5.Delete From End\n6.Delete From Position\n7.Display\n8.Count Nodes\n9.Reverse LL\n10.Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                printf("\nEnter Value: ");
                scanf("%d", &val);
                insertBeginning(val);
                break;
            }
            case 2: {
                printf("\nEnter Value: ");
                scanf("%d", &val);
                insertEnd(val);
                break;
            }
            case 3: {
                printf("\nEnter Position(Starts From 1): ");
                scanf("%d", &pos);
                printf("\nEnter Value: ");
                scanf("%d", &val);
                insertPosition(pos, val);
                break;
            }
            case 4: {
                deleteBeginning();
                break;
            }
            case 5: {
                deleteEnd();
                break;
            }
            case 6: {
                printf("\nEnter Position(Starts From 1): ");
                scanf("%d", &pos);
                deletePosition(pos);
                break;
            }
            case 7: {
                display();
                break;
            }
            case 8: {
                val = count();
                printf("\nCount: %d", val);
                break;
            }
            case 9: {
                reverse();
                break;
            }
            case 10: {
                printf("\nProgram Terminated Successfully.");
                break;
            }
            default: {
                printf("\nInvalid Choice.");
            }
        }
    } while(ch != 10);
}