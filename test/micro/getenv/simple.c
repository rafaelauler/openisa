#include <stdio.h>

int
main() {
  char *mypath = getenv("PATH");
  printf("PATH = ");
  puts(mypath);
}
