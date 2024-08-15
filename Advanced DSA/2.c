#include<stdio.h>
void displaySet(int *arr, int n) {
    int i;
    for(i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
} 

void selectionSort(int * arr, int n) {
    int i, j, temp, minIndex;
    for(i = 0; i < n-1; i++) {
        minIndex = i;
        for(j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        printf("Data Set After Iteration %d: ", i+1);
        displaySet(arr, n);
    }
}

void main() {
    int arr[] = {27,15,39,21,28,70};
    printf("Original Data Set: ");
    displaySet(arr, 6);
    selectionSort(arr, 6);
    printf("Sorted Data Set: ");
    displaySet(arr, 6);
}