class check_sign {
  public static boolean is_positive(int num) {
    return num >> (Integer.BYTES * 8 - 1) == 0;
  }
  public static void main(String[] args) {
    System.out.println(is_positive(10));
    System.out.println(is_positive(-10));
  }
}