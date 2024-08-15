#include<stdio.h>
void displaySet(int *arr, int n) {
    int i;
    for(i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
} 

int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j <= high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int * arr, int low, int high) {
    static int c = 1;
    if(low < high) {
        int part = partition(arr, low, high);
        if(c != 1) {
            printf("Data Set After Recursive Call %d: ", c-1);
            displaySet(arr, 6);
        }
        c++;
        quickSort(arr, low, part - 1);
        quickSort(arr, part + 1, high);
    }
}

void main() {
    int arr[] = {27,15,39,21,28,70};
    printf("Original Data Set: ");
    displaySet(arr, 6);
    quickSort(arr, 0, 5);
    printf("Sorted Data Set: ");
    displaySet(arr, 6);
}