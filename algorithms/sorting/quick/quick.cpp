#include <stdio.h>

void quick(int* arr, int l, int h) {
  if (l>=h) {
    return;
  }

  int p=arr[l], i=l, j=h;

  while (i<=j) {
    if (arr[i]>p) {
      int temp = arr[i];
      arr[i]=arr[j];
      arr[j--]=temp;
    }
    else if (arr[j]<=p) {
      int temp = arr[j];
      arr[j]=arr[i];
      arr[i++]=temp;
    }
    else {
      i++;
      j--;
    }
  }

  quick(arr, l, j);
  quick(arr, i, h);
  arr[j]=p;
}

int main() {
  int num[] = {7, 8, 2, 5, 6, 2};
  int len = 6;
  quick(num, 0, len-1);
  
  for (int i = 0; i < len; i++) {
    printf("%d ", num[i]);
  }
  printf("\n");
}