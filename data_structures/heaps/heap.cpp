#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max_heap[10] = {};
int size = 1;

void swap(int i, int j) {
  int temp = max_heap[i];
  max_heap[i]=max_heap[j];
  max_heap[j]=temp;
}

void sift_up(int i) {
  while (i>1) {
    if (max_heap[i/2] < max_heap[i]) {
      swap(i/2, i);
    }
    i/=2;
  }
}

void insert(int val) {
  max_heap[size]=val;
  sift_up(size++);
}

int get_max() {
  return max_heap[1];
}

int get_size() {
  return size-1;
}

bool is_empty() {
  return get_size()==0;
}

int main() {
  insert(10);
  insert(20);
  insert(30);
  insert(330);
  insert(3);
  insert(2);

  int loop;
  for(loop = 0; loop < 10; loop++)
      printf("%d ", max_heap[loop]);

  printf("\n");
  // printf("Max %d\n", get_max());
}