#include <stdio.h>
int queue[10], max = 10, front=-1, rear=-1;

void enqueue(int val) {
    if(rear == max-1) {
        printf("Queue Overflow");
        return;
    }
    if(front == -1) {
        front++;
    }
    rear++;
    queue[rear] = val;
}

int dequeue() {
    int val;
    if(front == -1) {
        printf("Queue Underflow");
        return -1;
    }
    val = queue[front];
    front++;
    return val;
}

void display() {
    if(front == -1) {
        printf("Queue Empty");
        return;
    }
    printf("\nQUEUE ELEMENTS :-\n");
    for(int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int ch, val;
    do {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                printf("Enter Element: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            }
            case 2: {
                val = dequeue();
                if(val != -1) {
                    printf("\nDeleted Element: %d", val);
                }
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                printf("\nProgram Terminated Successfully.");
                break;
            }
            default: {
                printf("\nInvalid Choice");
            }
        }
    } while(ch != 4);
    
    return 0;
}
