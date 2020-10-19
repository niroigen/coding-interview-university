def get_shortest_unique_substring(arr, str):
  # make map containing characters needed
  # local_optimal
  # global_optimal
  # start_idx=0
  # end_idx=0
  
  map = {}
  for c in arr:
    map[c]=0
  
  start=0
  
  
  globalans=str
  num_chars=0
  for i,c in enumerate(str):
    if c in map:
      if map[c]==0:
        num_chars+=1
      map[c]+=1
    
    while num_chars==len(arr):
      globalans=min(globalans, str[start,i+1], key=len)
      c=str[start]
      if c in map:
        if map[c]==1:
          num_chars-=1
        map[c]-=1
      start+=1
  return globalans

str = "xyyzyzyx"
arr = ['x','y','z']
print(get_shortest_unique_substring(arr, str))