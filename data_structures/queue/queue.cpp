#include <stdio.h>
#include <stdlib.h>

class LinkedList {
  struct Node {
    int value;
    Node* next;
    Node* prev;
  };

  Node* head;
  Node* tail;
  int size;

  public:

  LinkedList() {
    head = new Node();
    tail = new Node();
    size = 0;
  }

  void push_front(int value) {
    Node* node = new Node();
    node->value = value;

    if (size == 0) {
      head->next = node;
      tail->prev = node;
    }
    else {
      head->next->prev = node;
      node->next = head->next;
      head->next = node;
    }
    size++;
  }

  int pop_back() {
    if (size == 0) {
      return -1;
    }
    else {
      int value = tail->prev->value;
      Node* node = tail->prev;
      
      if (size == 1) {
        tail->prev = nullptr;
        head->next = nullptr;
      }
      else {
        tail->prev = tail->prev->prev;
      }

      delete node;
      size--;
      return value;
    }
  }

  int front() {
    if (size == 0) {
      return -1;
    }
    else {
      return head->next->value;
    }
  }

  int back() {
    if (size == 0) {
      return -1;
    }
    else {
      return tail->prev->value;
    }
  }
};

int main() {
  LinkedList list;

  list.push_front(10);
  list.push_front(20);
  list.push_front(30);
  list.push_front(40);

  printf("Front %d\n", list.front());
  printf("Back %d\n\n", list.back());

  printf("Finishing job %d\n\n", list.pop_back());
  printf("Finishing job %d\n\n", list.pop_back());
  printf("Finishing job %d\n\n", list.pop_back());
  printf("Finishing job %d\n\n", list.pop_back());
}