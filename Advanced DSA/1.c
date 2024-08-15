#include<stdio.h>
void displaySet(int *arr, int n) {
    int i;
    for(i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
} 

void bubbleSort(int * arr, int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        printf("Data Set After Iteration %d: ", i+1);
        displaySet(arr, n);
    }
}

void main() {
    int arr[] = {27,15,39,21,28,70};
    printf("Original Data Set: ");
    displaySet(arr, 6);
    bubbleSort(arr, 6);
    printf("Sorted Data Set: ");
    displaySet(arr, 6);
}