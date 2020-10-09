#include <stdio.h>

int binarySearchIterative(int* arr, int target, int size) {
  int l = 0;
  int r = size-1;

  while (l <= r) {
    int mid = (l+r)/2;
    if (*(arr+mid) == target) {
      return 1;
    }
    else if(*(arr+mid) < target) {
      l = mid+1;
    }
    else {
      r = mid-1;
    }
  }

  return 0;
}

int binarySearchRecursive(int* arr, int target, int size, int l, int r) {
  if (l > r) {
    return 0;
  }
  else {
    int mid = (l+r)/2;
    if (arr[mid] == target) {
      return 1;
    }
    else if (arr[mid] < target) {
      return binarySearchRecursive(arr, target, size, mid+1, r);
    }
    else {
      return binarySearchRecursive(arr, target, size, l, mid-1);
    }
  }
}

int main() {
  int arr[] = {1,2,3,4,5,6};

  printf("Finding 2, %d\n", binarySearchIterative(arr, 2, 6));
  printf("Finding 10, %d\n\n", binarySearchIterative(arr, 10, 6));

  printf("Finding 2, %d\n", binarySearchRecursive(arr, 2, 6,0,5));
  printf("Finding 10, %d\n", binarySearchRecursive(arr, 10, 6,0,5));
}