#include <stdio.h>

int is_positive(int number) {
  return number >> (sizeof(int)*8 - 1) == 0;
}

int opposite_signs(int n1, int n2) {
  return n1 >> (sizeof(int)*8 - 1) != n2 >> (sizeof(int)*8 - 1);
}

int abs(int n) {
  int mask = 1<<31;
  return n^mask;
}

int main() {
  printf("%d\n",is_positive(10));
  printf("%d\n",is_positive(2323));
  printf("%d\n",is_positive(1001));
  
  printf("%d\n",is_positive(-10));
  printf("%d\n",is_positive(-11));
  printf("%d\n\n",is_positive(-13));

  printf("%d\n",opposite_signs(-13,13));
  printf("%d\n",opposite_signs(-13,-13));
  printf("%d\n\n",opposite_signs(-13,-23));

  printf("test %d\n\n", 1<<31);

  printf("%d\n",abs(10));
  printf("%d\n",abs(-110));
  printf("%d\n",abs(-10));

}