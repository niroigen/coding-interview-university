#include <stdio.h>

void print(int* arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  
  printf("\n");
}

void quick(int* arr, int l, int h) {
  if (l>=h) {
    return;
  }

  int p = arr[l], i=l, j=h;

  while(i<=j) {
    if(arr[i]>p) {
      int temp=arr[j];
      arr[j--]=arr[i];
      arr[i]=temp;
    }
    else {
      i++;
    }
  }


  printf("Pivot %d in location %d\n", p, i);
  printf("i %d j %d\n", i, j);
  print(arr, 6);  
  quick(arr, l+1, j);
  arr[i]=p;
  quick(arr, i, h);
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