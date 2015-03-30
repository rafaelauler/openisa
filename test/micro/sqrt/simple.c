#include <stdio.h>
#include <math.h>

int
main() {
  float f;
  printf("Type in a float value: ");
  scanf("%f", &f);
  printf("%d Sqrt = %f\n", 0, sqrtf(f));
}
