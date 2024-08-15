#include <stdio.h>
int queue[3], max = 3, front=-1, rear=-1;

void enqueue(int val) {
    if((rear+1) % max == front) {
        printf("Queue Overflow");
        return;
    }
    if(front == -1) {
        front = (front+1) % max;
    }
    rear = (rear + 1) % max;
    queue[rear] = val;
}

int dequeue() {
    int val;
    if(front == -1) {
        printf("Queue Underflow");
        return -1;
    }
    val = queue[front];
    if(front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front+1) % max;
    }
    return val;
}

void display() {
    if(front == -1) {
        printf("Queue Empty");
        return;
    }
    printf("\nQUEUE ELEMENTS :-\n");
    for(int i = front; i != rear; i = (i + 1) % max) {
        printf("%d ", queue[i]);
    }
    printf("%d", queue[rear]);
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

