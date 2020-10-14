class Heap:
  def __init__(self):
    self.max_heap=[0]*10
    self.size=1
  
  def sift_down(self, i):
    if i<self.size:
      l=2*i
      r=2*i+1
      if (l<=self.size and r<=self.size) and (self.max_heap[i] < self.max_heap[l] or self.max_heap[i] < self.max_heap[l]):
        m= l if self.max_heap[l] > self.max_heap[r] else r
        self.max_heap[m], self.max_heap[i] = self.max_heap[i], self.max_heap[m]
        self.sift_down(m)
      elif l<=self.size and self.max_heap[i] < self.max_heap[l]:
        self.max_heap[l], self.max_heap[i] = self.max_heap[i], self.max_heap[l]
        self.sift_down(l)
  
  def extract_max(self):
    self.size-=1
    self.max_heap[1]=self.max_heap[self.size]
    self.sift_down(1)

  def sift_up(self, i):
    while i>1:
      if self.max_heap[i//2] < self.max_heap[i]:
        self.max_heap[i//2], self.max_heap[i] = self.max_heap[i], self.max_heap[i//2]
      i//=2

  def insert(self, value):
    self.max_heap[self.size]=value
    self.sift_up(self.size)
    self.size+=1

  def get_max(self):
    return self.max_heap[1]

  def get_size(self):
    return self.size - 1
  
  def is_empty(self):
    return self.get_size()==0

h = Heap()
h.insert(10)
h.insert(20)
h.insert(30)
h.insert(330)
h.insert(3)
h.insert(2)

print(h.max_heap)

h.extract_max()
h.extract_max()

print(h.max_heap)
