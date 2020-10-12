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
  if (*root==NULL) {
    *root=createNode(value);
  }
  else if (value < (*root)->value) {
    insert(&(*root)->left, value);
  }
  else {
    insert(&(*root)->right, value);
  }
}

int main() {
  struct Node* root=NULL;
  insert(&root, 15);
  insert(&root, 20);
  insert(&root, 10);
  insert(&root, 50);

  printf("Root value %d\n", root->value);
  printf("Right value %d\n", root->right->value);
  printf("Let value %d\n", root->left->value);
  printf("Right's right %d\n", root->right->right->value);

}
