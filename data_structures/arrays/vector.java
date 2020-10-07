class Vector {
  int cap;
  int size;
  int[] array;
  
  public Vector(int cap) {
    size = 0;
    this.cap = cap;
    array = new int[cap];
  }

  public int size() {
    return size;
  }

  public int capacity() {
    return cap;
  }

  public boolean is_empty() {
    return size == 0;
  }

  public int at(int index) {
    if (index < 0 || index >= size) {
      return -1;
    }
    else {
      return array[index];
    }
  }

  public void push(int value) {
    if (size == cap) {
      resize(cap*2);
    }

    array[size++] = value;
  }

  public void insert(int index, int value) {
    if (index < 0 || index >= size) {
      return;
    }
    else {
      for (int i = size; i > index; i--) {
        array[i] = array[i-1];
      }
      array[index] = value;
      size++;
    }
  }

  public void prepend(int value) {
    insert(0, value);
  }

  public int pop() {
    if (size == 0) {
      return -1;
    }
    else {
      if (size <= cap/4) {
        resize(cap/2);
      }

      return array[--size];
    }
  }

  public void delete(int index) {
    if (index < 0 || index >= size) {
      return;
    }
    else {
      for (int i = index; i < size; i++) {
        array[i] = array[i+1];
      }
      size--;
    }
  }

  public void remove(int value) {
    int i = 0;

    while (i < size) {
      if (array[i] == value) {
        delete(i);
      }
      else {
        i++;
      }
    }
  }

  public boolean find(int value) {
    for (int i = 0; i < size; i++) {
      if (array[i] == value) {
        return true;
      }
    }

    return false;
  }

  private void resize(int new_cap) {
    int[] new_arr = new int[new_cap];

    for (int i = 0; i < size; i++) {
      new_arr[i] = array[i];
    }

    cap = new_cap;
  }

  public static void main(String[] args) {
    Vector v1 = new Vector(10);

    System.out.println("Is Empty: " + v1.is_empty());
  
    for (int i = 0; i < 8; i++) {
      v1.push(i);
    }

    v1.prepend(40);

    System.out.println("Vector size: " + v1.size());
    
    v1.remove(4);
    v1.remove(40);
  
    System.out.println("vector size: " + v1.size());
    System.out.println("vector capacity " + v1.capacity());
    System.out.println("Is Empty " + v1.is_empty());
  
    System.out.println("Trying to find 40 " + v1.find(40));
    System.out.println("Trying to find 5 " + v1.find(5));
  }
}