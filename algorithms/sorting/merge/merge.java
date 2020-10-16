public class merge {
  static void print(int[] arr) {
    for(int i : arr) {
      System.out.print(i + " ");
    }
    System.out.println();
  }

  static int[] merge_sort(int[] arr, int l, int h) {
    if (l==h){
      return arr;
    }
    else {
      int mid = l + (h-l)/2;
      arr=merge_sort(arr, l, mid);
      arr=merge_sort(arr, mid+1, h);
      return sort(arr, l, mid, h);
    }
  }

  static int[] sort(int[] arr, int l, int mid, int h) {
    int i=l, j=mid+1, idx=0, size=h-l+1;
    int[] aux = new int[size];

    System.out.println("l " + l + " mid " + mid + " h "+ h); 

    while(i<mid+1 && j<h+1) {
      if (arr[i]<arr[j]) aux[idx++]=arr[i++];
      else aux[idx++]=arr[j++];
    }

    while(i<mid+1) aux[idx++]=arr[i++];
    while(j<h+1) aux[idx++]=arr[j++];

    print(aux);

    for (i = 0; i < size; i++) {
      arr[i+l]=aux[i];
    }

    return arr;
  }
  public static void main(String[] args) {
    int arr[] = {2,4,4,5,1,2,9};
    
    arr=merge_sort(arr, 0, 6);

    print(arr);
  }
}
