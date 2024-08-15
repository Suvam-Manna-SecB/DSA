//Write a program to allocate memory using calloc() and then reallocate the 
previously allocated memory using realloc(). Display the elements which have 
been taken after reallocation.

#include <stdio.h> 
#include <stdlib.h> 
 
int main() 
{ 
    int n, new_size, i; 
 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    int *arr = (int *)calloc(n, sizeof(int)); 
 
    if (arr == NULL) 
    { 
        printf("Memory allocation failed.\n"); 
        return 1; 
    } 
 
    printf("Enter %d elements:\n", n); 
    for (i = 0; i < n; ++i) 
    { 
        scanf("%d", &arr[i]); 
    } 
 
    printf("\nElements before reallocation:\n"); 
    for (i = 0; i < n; ++i) 
    { 
        printf("%d ", arr[i]); 
    } 
 
    printf("\nEnter the new size for reallocation: "); 
    scanf("%d", &new_size); 
 
    if (new_size > n) 
    { 
        arr = (int *)realloc(arr, new_size * sizeof(int)); 
 
        if (arr == NULL) 
        { 
            printf("Memory reallocation failed.\n"); 
            return 1; 
        } 
 
        printf("Enter %d additional elements:\n", new_size - n); 
        for (i = n; i < new_size; ++i) 
        { 
            scanf("%d", &arr[i]); 
        } 
    } 
    printf("\nElements after reallocation:\n"); 
    for (i = 0; i < new_size; ++i) 
    { 
        printf("%d ", arr[i]); 
    } 
 
    free(arr); 
 
    return 0; 
}