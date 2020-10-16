public class insertion {
  public static int find_location(int[] arr, int l, int r, int target) {
    if (l>r) {
      return l;
    }
    else {
      int mid = l + (r-l)/2;
      if (target > arr[mid]) {
        return find_location(arr, mid+1, r, target);
      }
      else if (target < arr[mid]) {
        return find_location(arr, l, mid-1, target);
      }
      else {
        return mid;
      }
    }
  }

  public static int[] shift(int[] arr, int start, int end) {
    for (int i = end; i > start; i--) {
      arr[i]=arr[i-1];
    }
    return arr;
  }

  public static int[] insert(int[] arr, int target, int size) {
    int loc = find_location(arr, 0, size-1, target);
    arr=shift(arr, loc, size);
    arr[loc]=target;
    return arr;
  }

  public static int[] insertion(int[] arr) {
    for(int i = 0; i < arr.length; i++) {
      arr=insert(arr, arr[i], i);
    }

    return arr;
  }
  public static void main(String[] args) {
    int arr[] = {2,4,4,5,1,2,9};
    
    arr=insertion(arr);

    for(int i : arr) {
      System.out.println(i);
    }
  }
}
