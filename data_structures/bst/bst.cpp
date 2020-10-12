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

int node_count(Node* root, int count) {
  if (root==NULL) {
    return count;
  }

  return node_count(root->left,count)+node_count(root->right,count)+1;
}

void inorder(Node* root) {
  if (root==NULL) {
    return;
  }

  inorder(root->left);
  printf("%d ", root->value);
  inorder(root->right);
}

void delete_tree(Node** root) {
  if (*root==NULL) {
    return;
  }

  delete_tree(&(*root)->left);
  delete_tree(&(*root)->right);
  (*root)->left=NULL;
  (*root)->right=NULL;
  delete *root;
  *root=NULL;
}

bool is_in_tree(Node* root, int value) {
  if (root==NULL) {
    return false;
  }
  if (root->value==value) {
    return true;
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

int height(Node* root, int h) {
  if (root == NULL) {
    return 0;
  }
  return max(height(root->left, h), height(root->right, h)) + 1;
}

int min_val(Node* root) {
  if (root==NULL) {
    return -1;
  }

  if (root->left!=NULL) {
    return min_val(root->left);
  }
  else {
    return root->value;
  }
}

int max_val(Node* root) {
  if (root == NULL) {
    return -1;
  }

  if (root->right!=NULL) {
    return max_val(root->right);
  }
  else {
    return root->value;
  }
}

int main() {
  Node* root=NULL;
  insert(&root, 15);
  insert(&root, 20);
  insert(&root, 5);
  insert(&root, 50);

  printf("Root value %d\n", root->value);
  printf("Right value %d\n", root->right->value);
  printf("Let value %d\n", root->left->value);
  printf("Right's right %d\n\n", root->right->right->value);

  printf("Node count %d\n", node_count(root,0));
  inorder(root);
  printf("\n");

  printf("Is in tree 10 %d\n", is_in_tree(root, 15));
  printf("Is in tree 40 %d\n", is_in_tree(root, 40));

  printf("Height of tree %d\n", height(root,0));

  printf("Minimum value %d\n", min_val(root));
  printf("Maximum value %d\n", max_val(root));

  delete_tree(&root);

  inorder(root);
  printf("\n");
}