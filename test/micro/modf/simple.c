#include <stdio.h>
#include <math.h>

int
main() {
  double f, f2;
  printf("Type in two double values: ");
  scanf("%lf %lf", &f, &f2);
  printf("%d modf = %lf\n", 0, modf(f, &f2));
  printf("%d %lf\n", 0, f2);
}
