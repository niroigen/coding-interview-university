#include <stdio.h>

bool binarySearchIterative(int* arr, int target, int size) {
  int l = 0;
  int r = size-1;

  while(l <= r) {
    int mid = (l+r)/2;;
    if (arr[mid] == target) {
      return true;
    }
    else if (arr[mid] < target) {
      l = mid+1;
    }
    else {
      r=mid-1;
    }
  }  

  return false;
}

bool binarySearchRecursive(int* arr, int target, int l, int r) {
  if (l > r) {
    return false;
  }
  else {
    int mid = (l+r)/2;
    if (arr[mid] == target) {
      return true;
    }
    else if (arr[mid] < target) {
      return binarySearchRecursive(arr, target, mid+1, r);
    }
    else {
      return binarySearchRecursive(arr, target, l, mid-1);
    }
  }
}

int main() {
  int arr[] = {1,2,3,4,5,6};

  printf("Finding 2, %d\n", binarySearchIterative(arr, 2, 6));
  printf("Finding 10, %d\n\n", binarySearchIterative(arr, 10, 6));

  printf("Finding 2, %d\n", binarySearchRecursive(arr, 2, 0,5));
  printf("Finding 10, %d\n", binarySearchRecursive(arr, 10, 0,5));
}