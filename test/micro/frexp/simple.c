#include <stdio.h>

double frexp(double, int*);

int
main() {
  int i;
  double res = frexp(2.0, &i);
  printf("frexp(2.0, %d) = %lf\n", i, res);
}
