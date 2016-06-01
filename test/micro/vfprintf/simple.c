#include <stdio.h>
#include <stdarg.h>

int print(int numargs, ...) {
  va_list ListPointer;
  va_start(ListPointer, numargs);
  vfprintf(stderr, "wuhulll %d %d\n\0", ListPointer);
  va_end(ListPointer);
  return 0;
}

int main() {
  print(2, 5, 7);
}
