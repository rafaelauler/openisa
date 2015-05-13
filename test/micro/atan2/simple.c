#include <stdio.h>
#include <math.h>

int
main() {
  double f, f2;
  printf("Type in two double values: ");
  scanf("%lf %lf", &f, &f2);
  printf("%d Sqrt = %lf\n", 0, atan2(f, f2));
}
