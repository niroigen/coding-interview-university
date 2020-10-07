#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int* ptr;
  int _size;
  int _capacity;
} vector;

void init(vector* vec) {
  vec->ptr = malloc(vec->_capacity * sizeof(int));
}

void deinit(vector* vec) {
  free(vec->ptr);
  vec->ptr = NULL;
}

// Would take O(n) time to move all values from old array to new one
void resize(vector* vec, int new_capacity) {
  int* new_ptr = malloc(new_capacity * sizeof(int));

  for (int i = 0; i < vec->_size; i++) {
    *(new_ptr+i) = *(vec->ptr+i);
  }

  free(vec->ptr);
  vec->ptr = new_ptr;
}

// O(1) time to get the size of the vector since it is saved in the struct
int size(vector* vec) {
  return vec->_size;
}

// O(1) time to get the capacity of the vector since it is saved in the struct
int capacity(vector* vec) {
  return vec->_capacity;
}

// O(1) time since all you have to do is check whether the size value is equal to 0
int is_empty(vector* vec) {
  return vec->_size == 0;
}

int at(vector* vec, int index) {
  if (index >= vec->_size) {
    return -1;
  }
  else {
    return *(vec->ptr+index);
  }
}

// O(1) to add in an element to the end, with an amortized time being added when a resizing would occur
void push(vector* vec, int value) {
  printf("Checking for Size of vector: %d\n", vec->_size);
  if (vec->_size == vec->_capacity) {
    resize(vec, vec->_capacity*2);
  }
  else {
    *(vec->ptr+vec->_size)=value;
  }
  vec->_size++;
}

// Having to move all the value to the right would take O(n) worst case
void insert(vector* vec, int index, int value) {
  // Do not insert if the index is invalid or the vector is full
  if (index < 0 || vec->_size == vec->_capacity) return;

  vec->_size++;
  for (int i = vec->_size-1; i > index; i--) {
    *(vec->ptr+i) = *(vec->ptr+i-1);
  }
  
  *(vec->ptr+index) = value;
}

// The same time complexity of insert so O(n)
void prepend(vector* vec, int value) {
  insert(vec, 0, value);
}

// To remove the value would take O(1), update the size and remove the values but amortized time of resizing
int pop(vector* vec) {
  // Edge case when there is no element
  if (vec->_size == 0) return -1;

  vec->_size--;
  int value = *(vec->ptr+vec->_size);

  if (vec->_size == vec->_capacity/4) {
    resize(vec, vec->_capacity/2);
  }

  return value;
}

// To delete the value at index we would have to move all the value, which would take a worst case of O(n) time
void delete(vector* vec, int index) {
  if (index < 0 || index >= vec->_size) return;

  for (int i = index; i < vec->_size-1; i++) {
    *(vec->ptr+i) = *(vec->ptr+i+1);
  }

  vec->_size--;
}

// At worst case if all elements are equal to the value then we would have to move the value every time
// So O(n^2)
void remove_value(vector* vec, int value) {
  int index = 0;

  while (index < vec->_size) {
    if (*(vec->ptr+index) == value) {
      delete(vec, index);
    }
    else {
      index++;
    }
  }
}

// Worst case scenario if the last element is the value we are looking for
// Would have to traverse through the entire array
// Therefore O(n) would the worst case time complexity
int find(vector* vec, int value) {
  for (int i = 0; i < vec->_size; i++) {
    if (*(vec->ptr+i) == value) return 1;
  }
  return 0;
}

int main() {
  vector vec = {NULL, 0, 10};
  init(&vec);

  printf("Vector size: %d\n", size(&vec));
  printf("Vector\'s capacity: %d\n", capacity(&vec));
  printf("Is Vector Empty: %d\n", is_empty(&vec));
  printf("Vector\'s value at index {%d}: %d\n",0, at(&vec, 0));

  push(&vec,10);
  push(&vec,30);

  insert(&vec, 1, 20);

  prepend(&vec, 0);

  printf("Vector size: %d\n", size(&vec));
  printf("Vector\'s capacity: %d\n", capacity(&vec));
  printf("Is Vector Empty: %d\n", is_empty(&vec));
  printf("Vector\'s value at index {%d}: %d\n\n",1, at(&vec, 1));
  printf("Deleting item at index 1\n");
  delete(&vec,1);
  printf("Vector\'s value at index {%d}: %d\n\n",1, at(&vec, 1));
  printf("Performing pop %d\n", pop(&vec));

  push(&vec,40);
  printf("Performing pop %d\n", pop(&vec));

  vector vec1 = {NULL, 0, 10};
  init(&vec1);
  printf("Vector 1\'s size now:%d\n", size(&vec1));

  for (int i = 0; i < 5; i++) {
    push(&vec1, 10);
  }
  push(&vec1, 20);
  printf("Vector 1\'s size now:%d\n", size(&vec1));

  remove_value(&vec1, 10);

  printf("Vector 1\'s size now:%d\n", size(&vec1));

  printf("Checking to see if value %d exists in Vector 1: %d\n", 20, find(&vec1, 20));

  vector vec2 = {NULL, 0, 1};
  init(&vec2);

  push(&vec2,1);
  push(&vec2,1);
  push(&vec2,1);
  push(&vec2,1);

  printf("\nSize of Vector 2 after resizing pushes: %d\n", size(&vec2));

  deinit(&vec);
  deinit(&vec1);
  deinit(&vec2);
}