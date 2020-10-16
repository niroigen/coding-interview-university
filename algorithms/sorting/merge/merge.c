#include <stdlib.h>
#include <stdio.h>

void sort(int* arr, int i, int j, int size) {
  int iend = j, jend = i+size, idx=0;
  int start = i;
  int* aux = malloc(size * sizeof(int));

  while (i<iend && j<jend) {
    if (arr[i]<arr[j]) aux[idx++]=arr[i++];
    else aux[idx++]=arr[j++];
  }
  while (i<iend) aux[idx++]=arr[i++];
  while (j<jend) aux[idx++]=arr[j++];

  for (int i=0; i<size; i++) {
    arr[start+i]=aux[i];
  }

  free(aux);
  aux=NULL;
}

void merge_sort(int* arr, int l, int h) {
  if (l==h) {
    return;
  }
  int mid = l + (h-l)/2;
  merge_sort(arr, l, mid);
  merge_sort(arr, mid+1, h);
  sort(arr, l, mid+1, h-l+1);
}

int main() {
  int num[] = {7, 8, 2, 4, 3, 2};
  merge_sort(num, 0, 5);
  
  for (int i = 0; i < 6 ; i++) {
    printf("%d ", num[i]);
  }
  printf("\n");
}