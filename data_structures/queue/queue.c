#include <stdio.h>
#include <stdlib.h>

struct Node {
  int value;
  struct Node* next;
  struct Node* prev;
};

struct LinkedList {
  struct Node* head;
  struct Node* tail;
  int size;
};

void init(struct LinkedList* list) {
  list->head = (struct Node*) malloc(sizeof(struct Node));
  list->tail = (struct Node*) malloc(sizeof(struct Node));
}

void push_front(struct LinkedList* list, int value) {
  struct Node* node = (struct Node*) malloc(sizeof(struct Node));
  node->value = value;
  if (list->size == 0) {
    list->head->next = node;
    list->tail->prev = node;
  }
  else {
    node->next = list->head->next;
    list->head->next->prev = node;
    list->head->next = node;
  }

  list->size++;
}

int pop_back(struct LinkedList* list) {
  if (list->size == 0) {
    return -1;
  }
  else  {
    int value = list->tail->prev->value;
    if (list->size == 1) {
      list->tail->prev = NULL;
      list->head->next = NULL;
    }
    else {
      struct Node* removed = list->tail->prev;
      list->tail->prev = list->tail->prev->prev;

      free(removed);
    }

    list->size--;
    return value;
  }
}

int front(struct LinkedList* list) {
  if (list->size == 0) {
    return -1;
  }
  else {
    return list->head->next->value;
  }
}

int back(struct LinkedList* list) {
  if (list->size == 0) {
    return -1;
  }
  else {
    return list->tail->prev->value;
  }
}

int empty(struct LinkedList* list) {
  return list->size == 0;
}

int main() {
  struct LinkedList list = {NULL, NULL, 0};
  init(&list);

  push_front(&list, 10);
  push_front(&list, 20);
  push_front(&list, 30);
  push_front(&list, 40);

  printf("Front %d\n", front(&list));
  printf("Back %d\n\n", back(&list));

  printf("Finishing job %d\n\n", pop_back(&list));
  printf("Finishing job %d\n\n", pop_back(&list));
  printf("Finishing job %d\n\n", pop_back(&list));
  printf("Finishing job %d\n\n", pop_back(&list));

}