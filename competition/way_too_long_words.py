import sys

n=int(input())
words=[]
for i in range(n):
  words.append(input())

max_length=10

for i in range(len(words)):
  if len(words[i])>max_length:
    print(words[i][0] + str(len(words[i])-2) + words[i][-1])
  else:
    print(words[i])