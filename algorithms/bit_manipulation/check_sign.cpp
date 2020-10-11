#include <stdio.h>

int is_positive(int number) {
  return number >> (sizeof(int) * 8 - 1) == 0;
}

int main() {
  printf("%d\n",is_positive(10));
  printf("%d\n",is_positive(2323));
  printf("%d\n",is_positive(1001));
  
  printf("%d\n",is_positive(-10));
  printf("%d\n",is_positive(-11));
  printf("%d\n",is_positive(-13));
}