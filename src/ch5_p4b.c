#include <stdio.h>

// μια λίγο διαφορετική υλοποίηση της insertion sort
void insertion_sort(int arr[], int size) {
  int i, j;
  for (i = 1; i < size; i++) {
    j = i;
    while ((j > 0) && (arr[j] < arr[j - 1])) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
      j--;
    }
  }
}

int main(void) {
  int numbers[] = {12, 11, 13, 5, 6};
  int size = sizeof(numbers) / sizeof(numbers[0]);
  printf("Original Array=");
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  insertion_sort(numbers, size);
  printf("\nSorted Array=");
  for (int i = 0; i < size; i++) {
    printf("%d ", numbers[i]);
  }
  return 0;
}
