#include <stdio.h>

int stack[10], max = 10, top = -1;

void push(int val) {
    if(top == max) {
        printf("Stack Overflow");
        return;
    }
    top++;
    stack[top] = val;
}

int pop() {
    int val;
    if(top == -1) {
        printf("Stack Underflow");
        return -1;
    }
    val = stack[top];
    top--;
    return val;
}

int peek() {
    if(top == -1) {
        printf("Stack Underflow");
        return -1;
    }
    return stack[top];
}

void display() {
    if(top == -1) {
        printf("Stack is Empty");
        return;
    }
    printf("\nSTACK ELEMENTS :-\n");
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

int main()
{
    int ch, val;
    do {
        printf("\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                printf("Enter Value: ");
                scanf("%d", &val);
                push(val);
                break;
            }
            case 2: {
                val = pop();
                if(val != -1) {
                    printf("Deleted Element: %d", val);
                }
                break;
            }
            case 3: {
                val = peek();
                if(val != -1) {
                    printf("Top Element: %d", val);
                }
                break;
            }
            case 4: {
                display();
                break;
            }
            case 5: {
                printf("Program Terminated Successfully.");
                break;
            }
            default: {
                printf("\nInvalid Choice");
            }
        }
    } while(ch != 5);
    
    return 0;
}
