#include <stdio.h>
#include <math.h>

int
main() {
  double f, f2;
  printf("Type in two double values: ");
  scanf("%lf %lf", &f, &f2);
  printf("isnan(f1) = %d\n", isnan(f));
  double f3 = f  / .0;
  printf("%d f / 0 = %lf\n", 0, f3);
  printf("isnan(f3) = %d\n", isnan(f3));
  double f4 = f3 / f3;
  printf("%d f3 / f3 = %lf\n", 0, f4);
  printf("isnan(f4) = %d\n", isnan(f4));
}
