#include <stdio.h>
#include <string.h>
#include <time.h>

int
main(int argc, char **argv) {
  char str[1024];
  time_t t;
  struct tm *tmp;

  t = time(NULL);
  tmp = localtime(&t);
  if (tmp == NULL) {
    printf("localtime failed...\n");
    return -1;
  }

  if (strftime(str, 1024, "%a %b %e %T %Y\n", tmp) == 0) {
    printf("strftime returned 0\n");
    return -1;
  }

  puts(str);
  return 0;
}
