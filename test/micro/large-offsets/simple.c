#include <stdio.h>
#include <string.h>

unsigned char myvec[20000];

int
main(int argc, char **argv) {
  int i;

  for (i = 0; i < 4000; ++i) {
    myvec[i] = i % 5;
  }

  myvec[19666] = 255;

  unsigned int count = 0;
  for (i = 0; i < 4000; ++i) {
    count += myvec[i];
  }

  printf("Count: %d\n", count);
}
