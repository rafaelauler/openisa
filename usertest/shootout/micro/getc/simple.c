#include <stdio.h>

int
main(int argc, char **argv) {
  printf("You typed char '%c'.\n", fgetc(stdin));
}
