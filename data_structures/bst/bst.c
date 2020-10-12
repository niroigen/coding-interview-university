#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node* left;
  struct Node* right;
  int value;
};

struct Node* createNode(int value) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->value=value;
  node->left=NULL;
  node->right=NULL;
  return node;
}

void insert(struct Node** root, int value) {
  struct Node* node = createNode(value);
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
  struct Node* root=NULL;
  insert(&root, 15);
  insert(&root, 20);
  insert(&root, 10);

  printf("Root value %d\n", root->value);
  printf("Right value %d\n", root->right->value);
  printf("Let value %d\n", root->left->value);
}
