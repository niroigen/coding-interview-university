import java.util.logging.SimpleFormatter;

class heap {
  int[] max_heap = new int[10];
  int size = 1;

  public void sift_up(int i) {
    while (i > 1) {
      if (max_heap[i/2] < max_heap[i]) {
        int temp = max_heap[i/2];
        max_heap[i/2] = max_heap[i];
        max_heap[i] = temp;
      }
      i/=2;
    }
  }

  public void insert(int value) {
    max_heap[size]=value;
    sift_up(size);
    size++;
  }

  public int get_max() {
    return max_heap[1];
  }

  public int size() {
    return size-1;
  }

  public boolean is_empty() {
    return size()==0;
  }

  public static void main(String[] args) {
    heap h = new heap();
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(330);
    h.insert(3);
    h.insert(2);
  
    int loop;
    for(loop = 0; loop < 10; loop++)
        System.out.println(h.max_heap[loop]);
  
    // printf("Max %d\n", get_max());
  }
}