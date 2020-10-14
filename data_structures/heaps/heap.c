#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int max_heap[10] = {0};
int size=0;

int left_child(int i) {
  return max_heap[2*i];
}

int right_child(int i) {
  return max_heap[2*i+1];
}

void sift_up(int i) {
  while (i!=1) {
    printf("%d, %d\n", max_heap[i/2], max_heap[i]);
    if (max_heap[i/2] < max_heap[i]) {
      int temp = max_heap[i/2];
      max_heap[i/2]=max_heap[i];
      max_heap[i]=temp;
      i/=2;
    }
    else {
      break;
    }
  }
}

int get_max() {
  return max_heap[1];
}

void insert(int value) {
  max_heap[++size]=value;
  sift_up(size);
}

int get_size() {
  return size-1;
}

int is_empty() {
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
  printf("Max %d\n", get_max());
}