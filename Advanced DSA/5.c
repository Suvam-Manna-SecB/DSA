#include<stdio.h>
void displaySet(int *arr, int n) {
    int i;
    for(i=0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
} 

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int size1 = m - l + 1;
    int size2 = r - m;
    int left[size1];
    int right[size2];
    for(i = 0; i < size1; i++) 
        left[i] = arr[l + i];
    for(j = 0; j < size2; j++)
        right[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while(i < size1 && j < size2) {
        if(left[i] < right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i < size1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while(j < size2) {
        arr[k] = right[j];
        j++;
        k++;
    }
    
}

void mergeSort(int * arr, int left, int right) {
    static int c = 1;
    if(left < right) {
        int mid = (left+right) / 2;
        if(c != 1) {
            printf("Data Set After Recursive Call %d: ", c-1);
            displaySet(arr, 6);
        }
        c++;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void main() {
    int arr[] = {27,15,39,21,28,70};
    printf("Original Data Set: ");
    displaySet(arr, 6);
    mergeSort(arr, 0, 5);
    printf("Sorted Data Set: ");
    displaySet(arr, 6);
}
