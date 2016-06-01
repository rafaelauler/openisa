#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int
main() {
  double f;
  char buf[256];
  printf("Type in a double value: ");
  scanf("%lf", &f);
  printf("\n\n");
  puts(gcvt(f, 5, buf));
}
