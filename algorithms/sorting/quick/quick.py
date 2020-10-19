def quick(arr, l, h):
  if (l>=h):
    return arr
  
  i=l
  j=h
  p=arr[l]

  while i<=j:
    if arr[i]>p:
      arr[i],arr[j]=arr[j],arr[i]
      j-=1
    elif arr[j]<p:
      arr[i],arr[j]=arr[j],arr[i]
      i+=1
    else:
      i+=1
      j-=1
  
  arr=quick(arr,l,j)
  arr=quick(arr,i,h)
  arr[i]=p
  return arr

print(quick([3,5,2,15,7,7,3,1], 0, 7))