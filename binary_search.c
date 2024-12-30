#include <stdio.h>
#include <stdlib.h>

// function to perform binary search on the array
int binary_search(int *arr, int size, int element)
{
    // set the lower and upper bounds of the search
    int low = 0;
    int high = size - 1;

    // loop until the bounds converge
    while (low <= high)
    {
        // find the middle element of the current search range
        int mid = (low + high) / 2;

        // if the middle element is the element we're looking for, return its index
        if (arr[mid] == element)
        {
            return mid;
        }
        // if the element is less than the middle element, search the left half of the array
        else if (element < arr[mid])
        {
            high = mid - 1;
        }
        // if the element is greater than the middle element, search the right half of the array
        else
        {
            low = mid + 1;
        }
    }

    // if the element is not found, return -1
    return -1;
}

int main()
{
    // create an array of size 10 and fill it with some values
    int size = 10;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // perform binary search on the array to find the element 5
    int index = binary_search(arr, size, 5);

    // print the index of the element, or -1 if it was not found
    printf("%d\n", index);

    return 0;
}
