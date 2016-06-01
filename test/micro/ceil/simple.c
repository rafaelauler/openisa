#include <stdio.h>
#include <math.h>

int
main() {
  double f, f2;
  printf("Type in two double values: ");
  scanf("%lf %lf", &f, &f2);
  printf("%d Ceil1 = %lf\n", 0, ceil(f));
  printf("%d Ceil2 = %lf\n", 0, ceil(f2));
}
