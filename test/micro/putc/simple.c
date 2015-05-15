#include <stdio.h>

int
main(int argc, char **argv) {
  printf("blbl");
  printf("putc('\\n', stdin) = %d\n", putc('\n', stdout));
}
