#include <stdio.h>

int find_location(int* arr, int l, int r, int target) {
  if (l>r) {
    return l;
  }
  else {
    int mid = l + (r-l)/2;
    if (target > arr[mid]) {
      return find_location(arr, mid+1, r, target);
    }
    else if (target < arr[mid]) {
      return find_location(arr, l, mid-1, target);
    }
    else {
      return mid;
    }
  }
}

void shift_elements(int* arr, int start, int end) {
  for (int i = end; i>start; i--) {
    arr[i]=arr[i-1];
  }
}

void insert_value(int* arr, int target, int sorted_size) {
  int loc = find_location(arr, 0, sorted_size-1, target);
  shift_elements(arr, loc, sorted_size);
  arr[loc]=target;
}

void insertion(int* arr, int size) {
  for(int i = 0; i < size; i++) {
    insert_value(arr, arr[i], i);
  }
}

int main() {
  int num[] = {7, 8, 2, 5, 6};
  insertion(num, 5);
  
  for (int i = 0; i < 5; i++) {
    printf("%d ", num[i]);
  }
  printf("\n");
}