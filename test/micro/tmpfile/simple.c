#include <stdio.h>

int
main(int argc, char **argv) {
  FILE *fp;
  int data = 10;

  fp = tmpfile();
  if (fp == NULL) {
    printf("tmpfile returned NULL\n");
    return -1;
  }

  int res = fwrite(&data, sizeof(int), 1, fp);

  printf("fwrite() returned %d\n", res);

  res = fclose(fp);
  printf("fclose() returned %d\n", res);

  return 0;
}
