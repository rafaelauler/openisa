#include <stdio.h>

int
main() {
  int n = 0;
  scanf("%d", &n);
  for (int i = 0; i < 4 && i < n; ++i) {
    printf("hi\n");
  }
}
