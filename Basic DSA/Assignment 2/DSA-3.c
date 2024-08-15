//Write a C program to pass an array to a function using Call by Reference, update 
the array values in the function, print the array elements both in the function and in 
the calling function. 

#include <stdio.h> 
 
void updateAndPrint(int *arr, int n) 
{ 
    int *ptr = &arr[0]; 
    int i; 
    printf("\nUpdating array elements in the function:\n"); 
    for (i = 0; i < n; ++i) 
    { 
        *ptr *= 2; 
        printf("%d ", *ptr); 
        ptr += 1; 
    } 
    printf("\n"); 
} 
 
int main() 
{ 
    int n, i; 
 
    printf("Enter the size of the array : "); 
    scanf("%d", &n); 
 
    int arr[100]; 
    printf("Enter %d elements for the array:\n", n); 
    for (i = 0; i < n; ++i) 
    { 
        scanf("%d", &arr[i]); 
    } 
 
    printf("\nArray elements before calling the function:\n"); 
    for (i = 0; i < n; ++i) 
    { 
        printf("%d ", arr[i]); 
    } 
 
    updateAndPrint(&arr[0], n); 
    return 0; 
}