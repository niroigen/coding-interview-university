#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

int is_in_tree(struct Node* root, int value) {
  if (root==NULL) return 0;

  if (root->value==value) {
    return 1;
  }
  else if (value < root->value) {
    return is_in_tree(root->left, value);
  }
  else {
    return is_in_tree(root->right, value);
  }
}

int max(int a, int b) {
  return a > b ? a : b;
}

int height(struct Node* root, int h) {
  if (root==NULL) {
    return 0;
  }

  return max(height(root->left, h), height(root->right, h)) + 1;
}

int min_val(struct Node* root) {
  if (root==NULL) {
    return -1;
  }

  if (root->left != NULL) {
    return min_val(root->left);
  }
  else {
    return root->value;
  }
}

int max_val(struct Node* root) {
  if (root==NULL) {
    return -1;
  }
  
  if (root->right != NULL) {
    return max_val(root->right);
  }
  else {
    return root->value;
  }
}

int is_binary_search_tree(struct Node* root, int min, int max) {
  if (root==NULL) {
    return 1;
  }

  if (root->value >= min && root->value <= max) {
    return is_binary_search_tree(root->left, min, root->value) & is_binary_search_tree(root->right, root->value, max);
  }
  else {
    return 0;
  }
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

  printf("Is in tree 10 %d\n", is_in_tree(root, 10));
  printf("Is in tree 40 %d\n", is_in_tree(root, 40));

  printf("Height of tree %d\n", height(root,0));

  printf("Minimum value %d\n", min_val(root));
  printf("Minimum value %d\n", max_val(root));

  printf("Is binary search tree %d\n", is_binary_search_tree(root, INT_MIN, INT_MAX));

  delete_tree(&root);
  inorder(root);
  printf("\n");
}
