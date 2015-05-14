#include <unistd.h>

int
main(int argc, char **argv) {
  int *errno = __errno_location();
  printf("errno = %d\n", *errno);
}
