#include <stdio.h>

int
main() {
  int i1, i2;
  printf("Type a number a to be shifted by another number b:\n");
  scanf("%d %d", &i1, &i2);
  printf("SLLV: %d\n", i1 << i2);
  printf("SRAV: %d\n", i1 >> i2);
  printf("SRLV: %d\n", (unsigned)i1 >> (unsigned)i2);
}
