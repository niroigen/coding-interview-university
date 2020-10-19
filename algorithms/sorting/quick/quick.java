public class quick {
  public static int[] quickSort(int[] arr, int l, int h) {
    if (l>=h) {
      return arr;
    }

    int i=l, j=h, p=arr[l];

    while (i<=j) {
      if (arr[i]>p) {
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j--]=temp;
      }
      else if (arr[j]<p) {
        int temp = arr[j];
        arr[j]=arr[i];
        arr[i++]=temp;
      }
      else {
        i++;
        j--;
      }
    }

    arr=quickSort(arr, l, j);
    arr=quickSort(arr, i+1, h);
    arr[i]=p;
    return arr;
  }

  public static void main(String[] args) {
    int arr[] = {2,4,4,5,1,2,9};
    
    arr=quickSort(arr, 0, arr.length-1);

    for(int i : arr) {
      System.out.println(i);
    }
  }
}