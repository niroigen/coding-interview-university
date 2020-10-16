public class bubble {
  public static int[] bubble_sort(int[] arr) {
    while(true) {
      boolean swapped = false;
      int i = 0;
      while(i+1<arr.length) {
        if(arr[i]>arr[i+1]) {
          int temp=arr[i];
          arr[i]=arr[i+1];
          arr[i+1]=temp;
          swapped=true;
        }
        i++;
      }

      if (!swapped) {
        return arr;
      }
    }
  }
  
  public static void main(String[] args) {
    int[] num = {3,2,5,6,1,4};
    num=bubble_sort(num);

    for (int number : num) {
      System.out.println(number);
    }
  }
}
