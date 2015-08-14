#include <stdio.h>

double ldexp(double, int);

int
main() {
    printf("ldexp(2.0, %d) = %lf\n", 2, ldexp(2.0, 2));
}
