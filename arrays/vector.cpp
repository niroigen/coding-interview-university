#include <iostream>

class vector {
private:
  void resize(int new_capacity);
  int* _pointer;
  int _size;
  int _capacity;
  
public:
  ~vector();
  vector(int capacity);
  int size();
  int capacity();
  bool is_empty();
  int at(int index);
  void push(int item);
  void insert(int index, int item);
  void prepend(int item);
  int pop();
  void delete_element(int index);
  void remove(int item);
  int find(int item);
};

vector::~vector() {
  printf("Deleting pointer\n");
  delete [] _pointer;
  _pointer = nullptr;
}

vector::vector(int capacity) : _capacity(capacity), _size(0) {
  printf("Initialized pointer to size %d\n", capacity);
  _pointer = new int[capacity];
}

// O(1) to add and amortized time of O(n) to add new spaces
void vector::push(int item) {
  if (_size >= _capacity) {
    resize(_capacity*2);
  }

  *(_pointer+_size)=item;
  _size++;
}

// O(1) to remove value at end, and O(n) to resize array
int vector::pop() {
  if (size > 0) {
    int val = *(_pointer+_size-1);

    if (_size == _capacity/4) {
      resize(_capacity/2);
    }

    _size--;

    return val;
  }
  else {
    return -1;
  }
}

// O(1) to check if index exists
int vector::at(int index) {
  if (index < _size) {
    return *(_pointer + index);
  }
  else {
    return -1;
  }
}

// O(1) to get value for size
int vector::size() {
  return _size;
}

// O(1) to get value for capacity
int vector::capacity() {
  return _capacity;
}

// O(1) to check
bool vector::is_empty() {
  return _size == 0;
}

// O(n) to move value to new array
void vector::resize(int new_capacity) {
  printf("Resizing to %d\n", new_capacity);

  int* new_ptr = new int[new_capacity];

  for (int i = 0; i < _size; i++) {
    *(new_ptr+i) = *(_pointer+i);
  }

  delete [] _pointer;
  _pointer = new_ptr;
  _capacity = new_capacity;
}

// O(n) to add value to an array and amortized time to resize when full
void vector::insert(int index, int item) {
  if (_size == _capacity) {
    resize(_capacity*2);
  }

  _size++;

  for (int i = _size - 1; i > index; i--) {
    *(_pointer+i+1) = *(_pointer+i);
  }

  *(_pointer+index) = item;
}

// O(n) to add item to beginning
void vector::prepend(int item) {
  insert(0,item);
}

// O(n) to delete an item and then resize
void vector::delete_element(int index) {
  if (_size > 0 && index < _size) {
    for (int i = index; i < _size-1; i++) {
      *(_pointer+index) = *(_pointer+index+1);
    }

    _size--;
  }
}

// O(n) to delete the item and then resize the array
void vector::remove(int item) {
  for (int i = 0; i < _size; i++) {
    if (*(_pointer+i) == item) {
      delete_element(i);
      break;
    }
  }
}

// O(n) to find the item
int vector::find(int item) {
  for (int i = 0; i < _size; i++) {
    if (*(_pointer+i) == item) {
      return i;
    }
  }

  return -1;
}

int main() {
  vector vec(2);
  printf("Is Empty: %d\n", vec.is_empty());

  for (int i = 0; i < 8; i++) {
    vec.push(i);
  }
  printf("Vector size: %d\n", vec.size());
  
  vec.remove(4);
  vec.remove(40);

  printf("Vector size: %d\n", vec.size());
  printf("Vector capacity: %d\n", vec.capacity());
  printf("Is Empty: %d\n", vec.is_empty());

  printf("Trying to find 40 %d\n", vec.find(40));
  printf("Trying to find 5 %d\n", vec.find(5));
}