#include <stdio.h>

void bubble(int* arr, int size) {
  while (true) {
    bool swapped = false;
    int i = 0;

    while (i+1<size) {
      if (arr[i]>arr[i+1]) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
        swapped=true;
      }
      i++;
    }

    if (!swapped) {
      return;
    }
  }
}

int main() {
  int num[] = {7, 4, 2, 5, 6};
  bubble(num, 5);
  
  for (int i = 0; i < 5; i++) {
    printf("%d ", num[i]);
  }
  printf("\n");
}