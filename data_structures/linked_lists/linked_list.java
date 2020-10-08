class linked_list {
  class Node {
    int value;
    Node next;

    Node() {}

    Node(int value) {
      this.value = value;
    }
  }

  public linked_list() {
    head = new Node();
  }

  Node head;
  int size;

  public int getSize() {
    return size;
  }

  public boolean empty() {
    return size == 0;
  }

  public int value_at(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    else {
      Node curr = head.next;
      for (int i = 0; i < index; i++) {
        curr = curr.next;
      }
      return curr.value;
    }
  }

  public void push_front(int value) {
    Node node = new Node(value);
    node.next = head.next;
    head.next = node;
    size++;
  }

  public int pop_front() {
    if (size == 0) {
      return -1;
    }
    int value = head.next.value;
    head.next = head.next.next;
    size--;
    return value;
  }

  public void push_back(int value) {
    Node curr = head;

    for (int i = 0; i < size; i++) {
      curr = curr.next;
    }

    curr.next = new Node(value);
    size++;
  }

  public int front() {
    if (size == 0) {
      return -1;
    }
    else {
      return head.next.value;
    }
  }

  public int back() {
    Node curr = head;
    for (int i = 0; i < size; i++) {
      curr = curr.next;
    }

    return curr.value;
  }

  public void insert(int index, int value) {
    if (index < 0 || index >= size) {
      return;
    }
    Node curr = head;
    for (int i = 0; i < index; i++) {
      curr = curr.next;
    }
    Node newNode = new Node(value);
    newNode.next = curr.next;
    curr.next = newNode;
    size++;
  }

  public void erase(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    else {
      Node curr = head;
      for (int i = 0; i < index; i++) {
        curr = curr.next;
      }
      curr.next = curr.next.next;
      size--;
    }
  }

  public int value_n_from_end(int n) {
    if (n < 0 || n >= size) {
      return -1;
    }
    else {
      return value_at(size-1-n);
    }
  }

  public void reverse() {
    Node prev = null;
    Node curr = head.next;
    Node next = curr;

    while(curr != null) {
      next = next.next;
      curr.next = prev;
      prev = curr;
      curr = next;
    }

    head.next = prev;
  }

  public void remove_value(int value) {
    Node curr = head.next;

    for (int i = 0; i < size; i++) {
      if (curr.value == value) {
        System.out.println("Attempt erase");
        erase(i);
        return;
      }
      curr = curr.next;
    }
  }

  public static void main(String[] args) {
    linked_list list = new linked_list();
    System.out.println("Size of the list " + list.getSize());
    System.out.println("Is Linked List Empty: " + list.empty());
    System.out.println("Value at index 0: " + list.value_at(0));
  
    list.push_front(10);
    System.out.println("Value at index 0: " + list.value_at(0));
    
    list.pop_front();
    System.out.println("Value at index 0: " + list.value_at(0));
  
    list.push_back(10);
    list.push_back(20);
    System.out.println("Value at index 0: " + list.value_at(0));
    System.out.println("Value at index 1: " + list.value_at(1));
  
    System.out.println("Front " + list.front());
    System.out.println("Back " + list.back());
  
    list.insert(1,15);
    System.out.println("Value at index 1: " + list.value_at(1));
  
    // list.erase(2);
    // list.erase(1);

    System.out.println("Back " + list.back());  
    System.out.println("Value from back at n = : " + list.value_n_from_end(1));
  
    System.out.println("Reverse");
    list.reverse();
    System.out.println("Front " + list.front());
    System.out.println("Back " + list.back());
  
    list.remove_value(10);

    list.remove_value(100);
    System.out.println("Back " + list.back());
  }
}