#include <stdio.h>

int a[100], n=100, size=0;

void insert() {
    if(n == size) {
        printf("Array is Full");
        return;
    }
    int val, pos;
    printf("Enter Value: ");
    scanf("%d", &val);
    printf("\nEnter Position: ");
    scanf("%d", &pos);
    for(int i=size-1; i >= pos; i--) {
        a[i+1] = a[i];
    }
    a[pos] = val;
    size++;
}

void delete() {
    if(size == 0) {
        printf("Array is Empty");
        return;
    }
    int pos;
    printf("\nEnter Position: ");
    scanf("%d", &pos);
    for(int i = pos; i < size; i++) {
        a[i] = a[i+1];
    }
    size--;
}

void display() {
    if(size == 0) {
        printf("\nArray is Empty");
        return;
    }
    for(int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
} 

int main()
{
    int ch;
    do {
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Exit\nEnter Choice: ");
        scanf("%d", &ch);
        switch(ch) {
            case 1: {
                insert(a, n, size);
                break;
            }
            case 2: {
                delete(a, size);
                break;
            }
            case 3: {
                display(a, size);
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
