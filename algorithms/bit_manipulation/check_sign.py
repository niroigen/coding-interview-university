import sys

def is_positive(num):
  return num >> (sys.getsizeof(int) * 8 - 1) == 0

print("%d\n" % (is_positive(10)))
print("%d\n" % (is_positive(2323)))
print("%d\n" % (is_positive(1001)))

print("%d\n" % (is_positive(-10)))
print("%d\n" % (is_positive(-11)))
print("%d\n" % (is_positive(-13)))