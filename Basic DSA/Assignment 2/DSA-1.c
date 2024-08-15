//Write a C program to read a 2D array (with most of the elements as 0s) and then 
represent the same array as Sparse Metrics.

#include <stdio.h> 
#define max_row 10 
#define max_col 10 
#define max_element max_row *max_col 
 
void SparseMatrix(int arr[max_row][max_col], int rows, int cols) 
{ 
    int sparse[max_element][3], k = 0, i, j; 
    for (i = 0; i < rows; ++i) 
    { 
        for (j = 0; j < cols; ++j) 
        { 
            if (arr[i][j] != 0) 
            { 
                sparse[k][0] = i; 
                sparse[k][1] = j; 
                sparse[k][2] = arr[i][j]; 
                k++; 
            } 
        } 
    } 
 
    printf("Sparse Matrix:\n"); 
    for (i = 0; i < k; ++i) 
    { 
        for (j = 0; j < 3; ++j) 
        { 
            printf("%d ", sparse[i][j]); 
        } 
        printf("\n"); 
    } 
} 
 
void main() 
{ 
    int rows, cols, i, j; 
 
    printf("Enter Number of Rows: "); 
    scanf("%d", &rows); 
    printf("Enter Number of Columns: "); 
    scanf("%d", &cols); 
 
    int array[max_row][max_col]; 
 
    printf("Enter Matrix Elements:\n"); 
    for (i = 0; i < rows; ++i) 
    { 
        for (j = 0; j < cols; ++j) 
        { 
            scanf("%d", &array[i][j]); 
        } 
    } 
 
    SparseMatrix(array, rows, cols); 
}