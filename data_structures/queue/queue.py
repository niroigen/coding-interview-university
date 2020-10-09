class Queue:
  class LinkedList:
    class Node:
      def __init__(self):
        self.value = None
        self.prev = None
        self.next = None

    def __init__(self):
      self._size = 0
      self.head = self.Node()
      self.tail = self.Node()

    def push_front(self, value):
      node = self.Node()
      node.value = value
      if self._size == 0:
        self.head.next = node
        self.tail.prev = node
      else:
        node.next = self.head.next
        self.head.next.prev = node
        self.head.next = node
      self._size+=1

    def pop_back(self):
      if self._size == 0:
        return -1
      else:
        value = self.tail.prev.value

        if self._size == 1:
          self.tail.prev = None
          self.head.next = None
        else:
          self.tail.prev = self.tail.prev.prev
        self._size-=1
        return value
  def __init__(self):
    self.list = self.LinkedList()

  def enqueue(self, value):
    self.list.push_front(value)
  
  def dequeue(self):
    return self.list.pop_back()

  def empty(self):
    return self.list._size == 0

q = Queue()

q.enqueue(10)
q.enqueue(20)
q.enqueue(30)
q.enqueue(40)

print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
print(q.dequeue())
