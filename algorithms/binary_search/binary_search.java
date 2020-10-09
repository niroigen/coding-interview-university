class binary_search {

  public static boolean binarySearchIterative(int[] arr, int target) {
    int l=0;
    int r=arr.length-1;

    while(l<=r) {
      int mid=(l+r)/2;
      if (arr[mid]==target) {
        return true;
      }
      else if(arr[mid]<target) {
        l=mid+1;
      }
      else {
        r=mid-1;
      }
    }

    return false;
  }

  public static boolean binarySearchRecursive(int[] arr, int target, int l, int r) {
    if (l>r) {
      return false;
    }
    else {
      int mid=(l+r)/2;
      if (arr[mid]==target) {
        return true;
      }
      else if (arr[mid]<target) {
        return binarySearchRecursive(arr, target, mid+1, r);
      }
      else {
        return binarySearchRecursive(arr, target, l, mid-1);
      }
    }
  }

  public static void main(String[] args) {
    int arr[] = {1,2,3,4,5,6};

    System.out.println("Finding 2, " + binarySearchIterative(arr, 2));
    System.out.println("Finding 10 " + binarySearchIterative(arr, 10));
  
    System.out.println("Finding 2, " + binarySearchRecursive(arr, 2, 0,5));
    System.out.println("Finding 10, " + binarySearchRecursive(arr, 10, 0,5));
  }
}