#include <stdio.h>
#include <stdlib.h>

// function to display the elements of the array in row-major order
void display_row_major(int **arr, int rows, int cols)
{
    // loop through the rows and columns of the array
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// function to display the elements of the array in column-major order
void display_column_major(int **arr, int rows, int cols)
{
    // loop through the columns and rows of the array
    for (int j = 0; j < cols; j++)
    {
        for (int i = 0; i < rows; i++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    // create a 2D array of size 3x3
    int rows = 3;
    int cols = 3;
    int **arr = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
    {
        arr[i] = malloc(cols * sizeof(int));
    }

    // fill the array with some values
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = i * cols + j;
        }
    }

    // display the array in row-major order
    printf("Row-major order:\n");
    display_row_major(arr, rows, cols);

    // display the array in column-major order
    printf("\nColumn-major order:\n");
    display_column_major(arr, rows, cols);

    // free the memory used by the array
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);

    return 0;
}
