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

int count_nodes(struct Node* root, int count) {
  if (root==NULL) {
    return count;
  }
  else {
    return count_nodes(root->left, count)+count_nodes(root->right, count)+1;
  }
}

void inorder(struct Node* root) {
  if (root==NULL) return;
  
  inorder(root->left);
  printf("%d ", root->value);
  inorder(root->right);
}

void delete_tree(struct Node** root) {
  if (*root==NULL) {
    return;
  }
  delete_tree(&(*root)->left);
  delete_tree(&(*root)->right);
  (*root)->left=NULL;
  (*root)->right=NULL;
  free(*root);
  *root=NULL;
}

int main() {
  struct Node* root=NULL;
  insert(&root, 15);
  insert(&root, 20);
  insert(&root, 10);
  insert(&root, 50);
  insert(&root, 60);

  printf("Root value %d\n", root->value);
  printf("Right value %d\n", root->right->value);
  printf("Let value %d\n", root->left->value);
  printf("Right's right %d\n\n", root->right->right->value);

  printf("Node count %d\n", count_nodes(root, 0));

  inorder(root);
  printf("\n");

  delete_tree(&root);
  inorder(root);
  printf("\n");
}
