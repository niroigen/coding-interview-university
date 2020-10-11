class Node:
  def __init__(self,value):
    self.value=value
    self.nodes=[]
  
  def add_child(self,value):
    self.nodes.append(Node(value))

root=Node(10)
root.add_child(15)
root.add_child(20)
root.add_child(35)

root.nodes[0].add_child(10)

print(len(root.nodes))
print(len(root.nodes[0].nodes))