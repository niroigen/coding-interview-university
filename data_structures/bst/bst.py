class Node:
  def __init__(self, value):
    self.value=value
    self.left=None
    self.right=None

def insert(root, value):
  if root==None:
    return Node(value)
  elif value<root.value:
    root.left=insert(root.left, value)
  else:
    root.right=insert(root.right, value)
  
  return root

root=None

root=insert(root, 15)
root=insert(root, 20)
root=insert(root, 10)
root=insert(root, 50)

print("Root value %d" % (root.value))
print("Right value %d" % (root.right.value))
print("Let value %d" % (root.left.value))
print("Right's right %d" % (root.right.right.value))

    