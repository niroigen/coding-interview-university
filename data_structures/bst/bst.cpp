#include <stdio.h>
#include <stdlib.h>

struct Node {
  Node* left;
  Node* right;
  int value;
};

Node* createNode(int value) {
  Node* node=new Node();
  node->value=value;
  node->left=NULL;
  node->right=NULL;
  return node;
}

void insert(Node** root, int value) {
  Node* node=createNode(value);
  if (*root==NULL) {
    *root=node;
  }
  else if (value < (*root)->value) {
    (*root)->left=node;
  }
  else {
    (*root)->right=node;
  }
}

int main() {
  Node* root=NULL;
  insert(&root, 15);
  insert(&root, 20);
  insert(&root, 10);

  printf("Root value %d\n", root->value);
  printf("Right value %d\n", root->right->value);
  printf("Let value %d\n", root->left->value);
}