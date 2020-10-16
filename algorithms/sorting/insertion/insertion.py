def find_location(arr, l, r, target):
  if l>r:
    return l
  else:
    mid=l+(r-l)//2
    if target > arr[mid]:
      return find_location(arr, mid+1, r, target)
    elif target < arr[mid]:
      return find_location(arr, l, mid-1, target)
    else:
      return mid

def shift(arr, start, end):
  for i in range(end, start, -1):
    arr[i]=arr[i-1]
  return arr

def insert(arr, target, size):
  loc=find_location(arr, 0, size-1, target)
  arr=shift(arr, loc, size)
  arr[loc]=target
  return arr

def insertion(arr):
  for i in range(len(arr)):
    arr=insert(arr, arr[i], i)
  return arr

print(insertion([3,2,2,1,5,6,9]))