#include <stdio.h>

int i = 0;

int
main(int argc, char **argv) {
  while(1) {
    printf("iteration %d\n", i++);
    if (i == 4)
      break;
  }
}
