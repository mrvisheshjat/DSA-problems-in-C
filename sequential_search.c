#include <stdio.h>
#include <stdlib.h>

// Function prototype for sequential search
int sequential_search(int *arr, int size, int target);

int main(int argc, char **argv) {
  // Read in the size of the array and the target element
  int size, target;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  printf("Enter the target element: ");
  scanf("%d", &target);

  // Read in the elements of the array
  int *arr = malloc(sizeof(int) * size);
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Perform the sequential search
  int index = sequential_search(arr, size, target);

  // Print the result
  if (index == -1) {
    printf("Element not found in the array.\n");
  } else {
    printf("Element found at index %d.\n", index);
  }

  return 0;
}

// Sequential search function
int sequential_search(int *arr, int size, int target) {
  // Iterate through the array and compare each element to the target
  for (int i = 0; i < size; i++) {
    if (arr[i] == target) {
      // If the target is found, return its index
      return i;
    }
  }

  // If the target is not found, return -1
  return -1;
}
