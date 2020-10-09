def binary_search_iterative(arr, target):
  l=0
  r=len(arr)-1

  while l<=r:
    mid = (l+r)//2
    if arr[mid]==target:
      return True
    elif arr[mid]<target:
      l=mid+1
    else:
      r=mid-1
  
  return False

def binary_search_recursive(arr, target, l, r):
  if l>r:
    return False
  else:
    mid=(l+r)//2
    if arr[mid]==target:
      return True
    elif arr[mid]<target:
      return binary_search_recursive(arr,target,mid+1,r)
    else:
      return binary_search_recursive(arr,target,l,mid+1)

arr = [1,2,3,4,5,6]

print("Finding 2, %d\n" % (binary_search_iterative(arr, 2)))
print("Finding 10, %d\n\n" % (binary_search_iterative(arr, 10)))

print("Finding 2, %d\n" % (binary_search_recursive(arr, 2,0,5)))
print("Finding 10, %d\n" % (binary_search_recursive(arr, 10,0,5)))