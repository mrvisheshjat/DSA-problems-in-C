#include <stdio.h>
#include <stdlib.h>

// function to insert an element into the array
void insert(int *arr, int *size, int index, int element)
{
    // if the index is greater than the size of the array, return
    if (index > *size)
    {
        return;
    }

    // increase the size of the array by 1
    *size = *size + 1;

    // allocate memory for the new array
    int *new_arr = malloc(*size * sizeof(int));

    // copy elements from the old array to the new array, up to the index
    for (int i = 0; i < index; i++)
    {
        new_arr[i] = arr[i];
    }

    // insert the new element at the specified index
    new_arr[index] = element;

    // copy the remaining elements from the old array to the new array
    for (int i = index + 1; i < *size; i++)
    {
        new_arr[i] = arr[i - 1];
    }

    // free the memory used by the old array
    free(arr);

    // update the pointer to the new array
    arr = new_arr;
}

int main()
{
    int size = 5;
    int arr[5] = {1, 2, 3, 4, 5};

    // insert the element 6 at index 3
    insert(arr, &size, 3, 6);

    // print the new array
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}