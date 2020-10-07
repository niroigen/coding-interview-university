class Vector:
  def __init__(self, capacity):
    self._size = 0
    self._capacity = capacity
    self._array = [0]*self._capacity
  
  def size(self):
    return self._size

  def capacity(self):
    return self._capacity

  def is_empty(self):
    return self._size == 0

  def at(self, index):
    if index < 0 or index >= self._size:
      return -1
    else:
      return self._array[index]

  def push(self, item):
    if self._capacity == self._size:
      self.resize(self._capacity*2)
      self._size+=1
    else:
      self._array[self._size] = item
      self._size+=1

  def insert(self, index, item):
    if index < 0 or index >= self._size or self._size == self._capacity:
      pass
    else:
      for i in range(self._size, index, -1):
        self._array[i]=self._array[i-1]
      self._array[index] = item
      self._size+=1

  def prepend(self, item):
    self.insert(0, item)

  def pop(self):
    if self._size == 0:
      return
    else:
      value = self._array[self._size-1]

      if self._size <= self._capacity / 4:
        self.resize(self._capacity//2)
        self._size-=1
      self._size-=1
      return value

  def delete(self, index):
    if index < 0 or index >= self._size:
      return
    else:
      for i in range(index, self._size-1):
        self._array[i] = self._array[i+1]
      self._size-=1

  def remove(self, item):
    index = 0

    while index < self._size:
      if self._array[index] == item:
        self.delete(index)
      else:
        index+=1

  def find(self, item):
    for i in range(0, self._size):
      if self._array[i] == item:
        return True
    return False

  def resize(self, new_capacity):
    new_arr = [0]*new_capacity

    for i in range(self._size):
      new_arr[i] = self._array[i]
    
    self._capacity = new_capacity
    
    self._array = new_arr

vec1 = Vector(10)

print('Size of vector is %d' % (vec1.size()))
print('Capacity of vector is %d' % (vec1.capacity()))
print('Is Vector empty? %s' % (vec1.is_empty()))
print('Value of array at index %d: %d' % (0, vec1.at(0)))

vec2 = Vector(10)
vec2.push(10)
vec2.push(10)
vec2.push(10)
vec2.push(10)

print('Value of array at index %d: %d' % (0, vec2.at(0)))

vec2.insert(2,20)

print(vec2._array)

print()
print("Removing 10")
vec2.remove(10)
print(vec2._array)

print()

v3 = Vector(3)
v3.push(1)
v3.push(2)
v3.push(3)

v3.delete(1)
print(v3._size)
print(v3._array)
print(v3.find(2))

v = Vector(32)

v.push(10)
v.push(10)
v.pop()

print(v.capacity())