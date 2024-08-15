#include<stdio.h>
void displaySet(int *arr, int n) {
    int i;
    for(i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
} 

void insertionSort(int * arr, int n) {
    int i, j, k;
    for(i = 1; i < n; i++) {
        k = arr[i];
        j = i-1;
        while(j >= 0 && arr[j] > k) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = k;
        printf("Data Set After Iteration %d: ", i);
        displaySet(arr, n);
    }
}

void main() {
    int arr[] = {27,15,39,21,28,70};
    printf("Original Data Set: ");
    displaySet(arr, 6);
    insertionSort(arr, 6);
    printf("Sorted Data Set: ");
    displaySet(arr, 6);
}
