#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Merge Sort
void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int left[n1], right[n2];

    for (i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        right[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int *arr, int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {

    int merge[20] = {500,450,400,350,300,250,200,180,160,150,100,90,80,70,60,50,40,30,20,10};
    int quick[20] = {500,450,400,350,300,250,200,180,160,150,100,90,80,70,60,50,40,30,20,10};
    
    int n = 20;


    clock_t start_m = clock();
    mergeSort(merge, 0, n - 1);
    clock_t end_m = clock();
    double time_m = ((double) (end_m - start_m)) / CLOCKS_PER_SEC;

    clock_t start_q = clock();
    quickSort(quick, 0, n - 1);
    clock_t end_q = clock();
    double time_q = ((double) (end_q - start_q)) / CLOCKS_PER_SEC;

    printf("Time taken for Merge Sort: %f seconds\n", time_m);
    printf("Time taken for Quick Sort: %f seconds\n", time_q);

    return 0;
}
