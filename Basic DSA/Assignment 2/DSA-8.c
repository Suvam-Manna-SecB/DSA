//Write a C program to search an element in an Array using dynamic memory 
allocation. 

#include <stdio.h> 
#include <stdlib.h> 
 
int searchElement(int *arr, int size, int key) 
{ 
    int i; 
    for (i = 0; i < size; ++i) 
    { 
        if (arr[i] == key) 
        { 
            return i; 
        } 
    } 
    return -1; 
} 
 
int main() 
{ 
    int n, key, i; 
 
    printf("Enter the size of the array: "); 
    scanf("%d", &n); 
 
    int *arr = (int *)malloc(n * sizeof(int)); 
 
    if (arr == NULL) 
    { 
        printf("Memory allocation failed.\n"); 
        return 1; 
    } 
 
    printf("Enter %d elements for the array:\n", n); 
    for (i = 0; i < n; ++i) 
    { 
        scanf("%d", &arr[i]); 
    } 
 
    printf("Enter the element to search: "); 
    scanf("%d", &key); 
 
    int index = searchElement(arr, n, key); 
 
    if (index != -1) 
    { 
        printf("Element %d found at index %d.\n", key, index); 
    } 
    else 
    { 
        printf("Element %d not found in the array.\n", key); 
    } 
 
    free(arr); 
 
    return 0; 
}