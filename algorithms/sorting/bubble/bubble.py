def bubble(arr):
  while True:
    swapped=False
    i=0
    while i+1<len(arr):
      if arr[i]>arr[i+1]:
        arr[i],arr[i+1]=arr[i+1],arr[i]
        swapped=True
      i+=1
    if not swapped:
      return arr

print(bubble([1,4,5,2,3,6]))