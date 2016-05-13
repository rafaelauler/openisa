#include <stdio.h>

int
main() {
  printf("lui with immediates: 1000000\n");
  printf("lui with relocation: 1000368\n");
  printf("loading far-away addresses: 1000000\n");
  printf("loading far-away float: 0 0.707107\n");
  printf("loading far-away double: 0 0.350000\n");
  printf("multiplying the two previous numbers: 0 0.247487\n");
  printf("10* double = int: 3 double: 3.500000\n");
}
