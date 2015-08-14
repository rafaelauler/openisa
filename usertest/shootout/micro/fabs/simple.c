#include <stdio.h>
#include <math.h>

int
main() {
  float f;
  printf("Type in a float value: ");
  scanf("%f", &f);
  printf("%d fabs = %f\n", 0, fabsf(f));
}
