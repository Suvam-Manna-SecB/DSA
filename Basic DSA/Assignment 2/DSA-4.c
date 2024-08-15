//Write a program to display n number of elements. Memory should be allocated 
dynamically using malloc().

#include <stdio.h> 
#include <stdlib.h> 
 
int main() 
{ 
    int n, i; 
    printf("Enter the number of elements: "); 
    scanf("%d", &n); 
 
    int *arr = (int *)malloc(n * sizeof(int)); 
 
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
 
    printf("\nElements of the array:\n"); 
    for (i = 0; i < n; ++i) 
    { 
        printf("%d ", arr[i]); 
    } 
 
    free(arr); 
 
    return 0; 
}