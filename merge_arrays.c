#include <stdio.h>
#include <stdlib.h>

// Function prototype for merging two arrays
void merge_arrays(int *arr1, int size1, int *arr2, int size2, int *result);

int main(int argc, char **argv) {
  // Read in the sizes of the arrays and allocate memory for them
  int size1, size2;
  printf("Enter the size of the first array: ");
  scanf("%d", &size1);
  printf("Enter the size of the second array: ");
  scanf("%d", &size2);
  int *arr1 = malloc(sizeof(int) * size1);
  int *arr2 = malloc(sizeof(int) * size2);
  int *result = malloc(sizeof(int) * (size1 + size2));

  // Read in the elements of the first array
  printf("Enter the elements of the first array: ");
  for (int i = 0; i < size1; i++) {
    scanf("%d", &arr1[i]);
  }

  // Read in the elements of the second array
  printf("Enter the elements of the second array: ");
  for (int i = 0; i < size2; i++) {
    scanf("%d", &arr2[i]);
  }

  // Merge the arrays
  merge_arrays(arr1, size1, arr2, size2, result);

  // Print the merged array
  printf("Merged array: ");
  for (int i = 0; i < size1 + size2; i++) {
    printf("%d ", result[i]);
  }
  printf("\n");

  return 0;
}

// Function to merge two arrays
void merge_arrays(int *arr1, int size1, int *arr2, int size2, int *result) {
  // Initialize indices for the arrays
  int i = 0, j = 0, k = 0;

  // Iterate through both arrays and compare their elements
  while (i < size1 && j < size2) {
    if (arr1[i] < arr2[j]) {
      // If the element in arr1 is smaller, add it to the result array
      result[k++] = arr1[i++];
    } else {
      // If the element in arr2 is smaller, add it to the result array
      result[k++] = arr2[j++];
    }
  }

  // Add any remaining elements from arr1 to the result array
  while (i < size1) {
    result[k++] = arr1[i++];
  }

  // Add any remaining elements from arr2 to the result array
  while (j < size2) {
    result[k++] = arr2[j++];
  }
}
