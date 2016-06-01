#include <stdio.h>
#include <stdarg.h>

int main() {
  char BUF[256];
  snprintf(BUF, 10, "wuhulll %d\n\0", 5);
  puts(BUF);
  return 0;
}
