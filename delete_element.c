#include <stdio.h>
#include <stdlib.h>

// Function prototype for deleting an element from an array
void delete_element(int *arr, int *size, int index);

int main(int argc, char **argv) {
  // Read in the size of the array and the index of the element to be deleted
  int size, index;
  printf("Enter the size of the array: ");
  scanf("%d", &size);
  printf("Enter the index of the element to be deleted: ");
  scanf("%d", &index);

  // Read in the elements of the array
  int *arr = malloc(sizeof(int) * size);
  printf("Enter the elements of the array: ");
  for (int i = 0; i < size; i++) {
    scanf("%d", &arr[i]);
  }

  // Delete the element from the array
  delete_element(arr, &size, index);

  // Print the modified array
  printf("Modified array: ");
  for (int i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}

// Function to delete an element from an array
void delete_element(int *arr, int *size, int index) {
  // Shift elements to the left to fill the gap left by the deleted element
  for (int i = index; i < *size - 1; i++) {
    arr[i] = arr[i + 1];
  }

  // Decrease the size of the array by 1
  (*size)--;
}