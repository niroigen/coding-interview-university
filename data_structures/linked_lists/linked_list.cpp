#include <iostream>

struct Node {
  int value;
  Node* next;

  Node() {
    next = nullptr;
  }
  ~Node() {
    if (next != nullptr) {
      delete next;
      next = nullptr;
    }
  }
};

class LinkedList {
  Node* head;
  int size;

  public:
    ~LinkedList() {
      if (head != nullptr) {
        delete head;
        head = nullptr;
      }
    }
    LinkedList() {
      head = new Node();
      size = 0;
    }
    
    int getSize() {
      return size;
    }

    bool empty() {
      return size == 0;
    }

    int value_at(int index) {
      if (index < 0 || index >= size) {
        return -1;
      }
      else {
        Node* node = head->next;
        for (int i = 0; i < index; i++) {
          node = node->next;
        }
        return node->value;
      }
    }

    void push_front(int value) {
      Node* node = new Node();
      node->value = value;
      node->next = head->next;
      head->next = node;
      size++;
    }

    int pop_front() {
      if (size == 0) {
        return -1;
      }
      else {
        int value = head->next->value;
        Node* node = head->next;
        head->next = head->next->next;
        delete node;
        size--;
        return value;
      }
    }

    void push_back(int value) {
      Node* curr = head;
      for (int i = 0; i < size; i++) {
        curr = curr->next;
      }
      Node* ans = new Node();
      ans->value = value;
      curr->next = ans;
      size++;
    }

    int pop_back() {
      if (size == 0) {
        return -1;
      }
      else {
        Node* curr = head;
        for (int i = 0; i < size-1; i++) {
          curr = curr->next;
        }
        int value = curr->next->value;

        Node* remove = curr->next;
        curr->next = curr->next->next;
        free(remove);

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
        Node* curr = head;

        for (int i = 0; i < size; i++) {
          curr = curr->next;
        }

        return curr->value;
      }
    }

    void insert(int index, int value) {
      if (index < 0 || index >= size) {
        return;
      }
      else {
        Node* curr = head;

        for (int i = 0; i < index; i++) {
          curr = curr->next;
        }

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = curr->next;
        curr->next = newNode;
        size++;
      }
    }

    void erase(int index) {
      if (index < 0 || index >= size) {
        return;
      }
      else {
        Node* cur = head;
        
        for (int i = 0; i < index; i++) {
          cur=cur->next;
        }
        Node* removed = cur->next;
        cur->next = cur->next->next;
        delete removed;
        size--;
      }
    }

    int value_n_from_end(int n) {
      if (n < 0 || n >= size) {
        return -1;
      }
      else {
        return value_at(size-1-n);
      }
    }

    void reverse() {
      Node* prev = nullptr;
      Node* cur = head->next;
      Node* next = cur;
    
      while(cur != nullptr) {
        next = next->next;
        cur->next = prev;
        prev = cur;
        cur = next;
      }
    
      head->next = prev;
    }

    void remove_value(int value) {
      Node* cur = head->next;
      for (int i = 0; i < size; i++) {
        if (cur->value == value) {
          erase(i);
          return;
        }
        cur=cur->next;
      }
    }
};

int main() {
  LinkedList list;
  printf("Size of the list %d\n", list.getSize());
  printf("Is Linked List Empty: %d\n", list.empty());
  printf("Value at index 0: %d\n\n", list.value_at(0));

  list.push_front(10);
  printf("Value at index 0: %d\n\n", list.value_at(0));
  
  list.pop_front();
  printf("Value at index 0: %d\n\n", list.value_at(0));

  list.push_back(10);
  list.push_back(20);
  printf("Value at index 0: %d\n", list.value_at(0));
  printf("Value at index 1: %d\n\n", list.value_at(1));

  printf("Front %d\n", list.front());
  printf("Back %d\n\n", list.back());

  list.insert(1,15);
  printf("Value at index 1: %d\n\n", list.value_at(1));

  // list.erase(2);
  // list.erase(1);
  printf("Back %d\n\n", list.back());

  printf("Value from back at n = %d: %d\n\n", 1, list.value_n_from_end(1));

  printf("Reverse\n");
  list.reverse();
  printf("Front %d\n", list.front());
  printf("Back %d\n\n", list.back());

  list.remove_value(10);
  list.remove_value(100);
  printf("Back %d\n\n", list.back());
}
