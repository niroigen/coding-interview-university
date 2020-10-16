def sort(arr, i, j, size):
  iend = j
  jend = i+size
  start = i
  idx = 0

  aux = [0]*size

  while i<iend and j<jend:
    if arr[i]<arr[j]: 
      aux[idx]=arr[i]
      idx+=1
      i+=1
    else:
      aux[idx]=arr[j]
      idx+=1
      j+=1
  while i<iend:
    aux[idx]=arr[i]
    idx+=1
    i+=1

  while j<jend:
    aux[idx]=arr[j]
    idx+=1
    j+=1

  for _i in range(size):
    arr[_i+start]=aux[_i]
  return arr

def merge_sort(arr, l, h):
  if l==h:
    return arr

  mid = l+(h-l)//2
  arr=merge_sort(arr, l, mid)
  arr=merge_sort(arr, mid+1, h)
  return sort(arr, l, mid+1, h-l+1)

print(merge_sort([4,3,26,8,42,1], 0, 5))