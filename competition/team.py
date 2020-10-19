import sys

n=int(input())

nums_solved=0
for i in range(n):
  if sum([int(x) for x in input().split()]) >= 2:
    nums_solved+=1

print(nums_solved)