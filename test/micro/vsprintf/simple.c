#include <stdio.h>
#include <stdarg.h>

int print(int numargs, ...) {
  char BUF[256];
  va_list ListPointer;
  va_start(ListPointer, numargs);
  vsprintf(BUF, "wuhulll %d %d\n\0", ListPointer);
  puts(BUF);
  va_end(ListPointer);
  return 0;
}

int main() {
  print(2, 5, 7);
}
