class LinkedList:
  class Node:
    def __init__(self, value):
      self.value = value
      self.next = None

  def __init__(self):
    self.head = self.Node(0)
    self._size = 0

  def size(self):
    return self._size
  
  def empty(self):
    return self._size == 0

  def value_at(self, index):
    if index < 0 or index >= self._size:
      return -1
    node = self.head
    for _ in range(index+1):
      node = node.next
    return node.value

  def push_front(self, value):
    node = self.Node(value)
    node.next = self.head.next
    self.head.next = node
    self._size+=1

  def pop_front(self):
    if self._size != 0:
      self.head.next = self.head.next.next
      self._size-=1

  def push_back(self, value):
    def helper(node, value):
      if node.next == None:
        node.next = self.Node(value)
      else:
        helper(node.next, value)
    helper(self.head, value)
    self._size+=1

  def front(self):
    if self.head.next == None:
      return -1
    else:
      return self.head.next.value

  def back(self):
    def helper(node):
      if node.next == None:
        return node.value
      else:
        return helper(node.next)
    return helper(self.head)

  def insert(self, index, value):
    if index < 0 or index >= self._size:
      return
    def helper(node, index, value):
      if index == 0:
        n = self.Node(value)
        n.next = node.next
        node.next = n
      else:
        helper(node.next, index-1, value)

    helper(self.head, index, value)
    self._size+=1

  def erase(self, index):
    if (index < 0 or index >= self._size):
      return
    
    def helper(node, index):
      if index == 0:
        node.next = node.next.next
      else:
        helper(node.next, index-1)
    helper(self.head, index)
    self._size-=1

  def value_n_from_end(self, n):
    if n < 0 or n >= self._size:
      return -1
    return self.value_at(self._size-1-n)

  def reverse(self):
    prev = None
    curr = self.head.next
    next_ = curr

    while curr != None:
      next_ = next_.next
      curr.next = prev
      prev = curr
      curr = next_
    
    self.head.next = prev

  def remove_value(self, value):
    def helper(node, value, index):
      if node.value == value:
        self.erase(index)
      elif node.next == None:
        return
      else:
        helper(node.next, value, index+1)
    helper(self.head, value, -1)

list = LinkedList()

print("Size of the list %d\n" % list.size())
print("Is Linked List Empty: %d\n" % list.empty())
print("Value at index 0: %d\n\n" % list.value_at(0))

list.push_front(10)
print("Value at index 0: %d\n\n" % list.value_at(0))

list.pop_front()
print("Value at index 0: %d\n\n"% list.value_at(0))

print("Size of the list %d\n" % list.size())
list.push_back(10)
list.push_back(20)
print("Value at index 0: %d\n" % list.value_at(0))
print("Value at index 1: %d\n\n" % list.value_at(1))

print("Front %d\n" % list.front())
print("Back %d\n\n" % list.back())

list.insert(1,15)
print("Value at index 1: %d\n\n" % list.value_at(1))

# list.erase(2)
# list.erase(1)
# print("Back %d\n\n" % list.back())

print("Value from back at n = %d: %d\n\n" % (1, list.value_n_from_end(1)))

print("Reverse\n")
list.reverse()
print("Front %d\n" % list.front())
print("Back %d\n\n" % list.back())

list.remove_value(10)
list.remove_value(100)
print("Back %d\n\n" % list.back())