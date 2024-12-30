#include <stdio.h>

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int new_element = 10;
  int index = 0;

  // Shift elements to the right
  for (int i = 4; i >= index; i--) {
    array[i+1] = array[i];
  }

  // Insert new element
  array[index] = new_element;

  // Print the updated array
  for (int i = 0; i < 6; i++) {
    printf("%d ", array[i]);
  }

  return 0;
}