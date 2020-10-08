#include <stdio.h>
#include <stdlib.h>

struct Node{
  int value;
  struct Node* next;
};

struct linked_list{
  struct Node* head;
  int size;
};

void init(struct linked_list* list) {
  list->head = (struct Node*)malloc(sizeof(struct Node));
}

int size(struct linked_list* list) {
  return list->size;
}

int empty(struct linked_list* list) {
  return list->size == 0;
}

int value_at(struct linked_list* list, int index) {
  if (index < 0 || index >= list->size) {
    return -1;
  }
  else {
    struct Node* n = list->head;
    for (int i = -1; i < index; i++)
      n=n->next;
    return n->value;
  }
}

void push_front(struct linked_list* list, int value) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->value = value;
  node->next = list->head->next;
  list->head->next = node;
  list->size++;
}

int pop_front(struct linked_list* list) {
  if (list->size == 0) {
    return -1;
  }
  else {
    int value = list->head->next->value;
    struct Node* node = list->head->next;
    free(node);
    list->size--;
    return value;
  }
}

void push_back(struct linked_list* list, int value) {
  struct Node* curr = list->head;
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->value = value;
  for (int i = 0; i < list->size; i++) {
    curr = curr->next;
  }
  curr->next = node;
  list->size++;
}

int pop_back(struct linked_list* list) {
  if (list->size == 0) {
    return 0;
  }
  else {
    struct Node* curr = list->head;
    for (int i = 0; i < list->size-1; i++) {
      curr = curr->next;
    }

    int value = curr->next->value;

    struct Node* removed = curr->next;
    curr->next = curr->next->next;
    free(removed);
    list->size--;
    return value;
  }
}

int front(struct linked_list* list) {
  if (list->size == 0) {
    return -1;
  }
  else {
    return list->head->next->value;
  }
}

int back(struct linked_list* list) {
  if (list->size == 0) {
    return -1;
  }
  else {
    struct Node* curr = list->head;
    for (int i = 0; i < list->size; i++) {
      curr = curr->next;
    }

    return curr->value;
  }
}

void insert(struct linked_list* list, int index, int value) {
  if (index < 0 || index > list->size) {
    return;
  }
  else {
    struct Node* curr = list->head;
    for (int i = 0; i < index; i++) {
      curr = curr->next;
    }

    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->value = value;
    node->next = curr->next;
    curr->next = node;
    list->size++;
  }
}

void erase(struct linked_list* list, int index) {
  if (index < 0 || index > list->size) {
    return;
  }
  else {
    struct Node* curr = list->head;
    for (int i = 0; i < index; i++) {
      curr=curr->next;
    }

    struct Node* removed = curr->next;
    curr->next = curr->next->next;
    free(removed);
    list->size--;
  }
}

int value_n_from_end(struct linked_list* list, int n) {
  if (n < 0 || n >= list->size) {
    return -1;
  }
  else {
    return value_at(list, list->size-1-n);
  }
}

void reverse(struct linked_list* list) {
  struct Node* prev = NULL;
  struct Node* curr = list->head->next;
  struct Node* next = curr;

  while (curr != NULL) {
    next = next->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  list->head->next = prev;
}

void remove_value(struct linked_list* list, int value) {
  struct Node* node = list->head->next;
  for (int i = 0; i < list->size; i++) {
    if (node->value==value) {
      erase(list, i);
      return;
    }
    node=node->next;
  }
}

int main() {
  struct linked_list list = {NULL, 0};
  init(&list);
  printf("Size of the list %d\n", size(&list));
  printf("Is Linked List Empty: %d\n", empty(&list));
  printf("Value at index 0: %d\n\n", value_at(&list,0));

  push_front(&list, 10);
  printf("Value at index 0: %d\n\n", value_at(&list,0));
  
  pop_front(&list);
  printf("Value at index 0: %d\n\n", value_at(&list,0));

  push_back(&list,10);
  push_back(&list,20);
  printf("Value at index 0: %d\n", value_at(&list,0));
  printf("Value at index 1: %d\n\n", value_at(&list,1));

  // printf("Popping back: %d\n\n", pop_back(&list));

  printf("Front %d\n\n", front(&list));
  printf("Back %d\n\n", back(&list));

  insert(&list, 1, 15);
  printf("Value at index 1: %d\n\n", value_at(&list,1));

  // erase(&list, 2);
  // erase(&list, 1);
  // printf("Back %d\n\n", back(&list));

  printf("Value from back at n = %d: %d\n\n", 1, value_n_from_end(&list,1));

  printf("Reverse\n");
  reverse(&list);
  printf("Front %d\n", front(&list));
  printf("Back %d\n\n", back(&list));

  remove_value(&list, 10);
  remove_value(&list, 100);
  printf("Back %d\n\n", back(&list));
}