#include <stdio.h>

int
main() {
  long long i1 = 1000000LL, i2 = 3LL;
  printf("Type 2123456789 and 3:\n");
  scanf("%lld %lld", &i1, &i2);
  printf("signed: %d %lld\n", 0, i1 * i2);
}
