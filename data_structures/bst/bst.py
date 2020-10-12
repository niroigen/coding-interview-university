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

def node_count(root, count):
  if root==None:
    return count
  else:
    return node_count(root.left,count)+node_count(root.right,count)+1

def delete_tree():
  return None

def is_in_tree(root, value):
  if root==None:
    return False
  
  elif root.value==value:
    return True
  elif value < root.value:
    return is_in_tree(root.left, value)
  else:
    return is_in_tree(root.right, value)

def inorder(root):
  if root==None:
    return
  
  inorder(root.left)
  print(root.value)
  inorder(root.right)

def height(root, h):
  if root==None:
    return 0
  return max(height(root.left, h), height(root.right, h))+1

def min_val(root):
  if root==None:
    return -1
  
  if root.left!=None:
    return min_val(root.left)
  else:
    return root.value

root=None

root=insert(root, 15)
root=insert(root, 20)
root=insert(root, 10)
root=insert(root, 50)
root=insert(root, 60)

print("Root value %d" % (root.value))
print("Right value %d" % (root.right.value))
print("Let value %d" % (root.left.value))
print("Right's right %d" % (root.right.right.value))
print("Node count %d" % (node_count(root,0)))
    
inorder(root)

print("Is in tree 10 %d\n" % (is_in_tree(root, 10)))
print("Is in tree 40 %d\n" % (is_in_tree(root, 40)))

print("Height of tree %d" % (height(root, 0)))

print("Minimum value %d" % (min_val(root)))

root=delete_tree()
inorder(root)