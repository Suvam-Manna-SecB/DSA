#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void bubbleSort(int *arr, int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

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

    int bubble[6] = {27,15,39,21,28,70};
    int quick[6] = {27,15,39,21,28,70};
    
    int n = 6;

    clock_t start_b = clock();
    bubbleSort(bubble, n);
    clock_t end_b = clock();
    double time_b = ((double) (end_b - start_b)) / CLOCKS_PER_SEC;

    clock_t start_q = clock();
    quickSort(quick, 0, n - 1);
    clock_t end_q = clock();
    double time_q = ((double) (end_q - start_q)) / CLOCKS_PER_SEC;

    printf("Time taken for Bubble Sort: %f seconds\n", time_b);
    printf("Time taken for Quick Sort: %f seconds\n", time_q);

    return 0;
}
