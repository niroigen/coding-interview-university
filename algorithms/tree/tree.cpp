#include <iostream>
#include <vector>

struct Node {
  int value;
  std::vector<Node*> children; 

  void add_child(int value) {
    Node* node = new Node();
    node->value = value;
    children.push_back(node);
  }
};

int main() {
  Node root;
  root.value = 10;

  root.add_child(30);
  root.add_child(40);
  root.add_child(50);
  root.add_child(60);

  root.children[0]->add_child(50);

  printf("Number of children %d\n", root.children.size());
  printf("Number of children %d\n", root.children[1]->children.size());
  
}
