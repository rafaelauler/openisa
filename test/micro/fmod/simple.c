#include <stdio.h>
#include <math.h>

int
main() {
  double f, f2;
  printf("Type in two double values: ");
  scanf("%lf %lf", &f, &f2);
  printf("%d fmod = %lf\n", 0, fmod(f, f2));
}
