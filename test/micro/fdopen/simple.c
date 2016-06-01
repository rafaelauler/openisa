#include <stdio.h>

int
main(int argc, char **argv) {
  int fd = 0;
  FILE *fp = NULL;
  char buf[256];

  fd = open("testcase.txt", 0);
  if (fd == -1) {
    printf("open returned -1!\n");
    return -1;
  }

  fp = fdopen(fd, "r");
  if (fp == NULL) {
    printf("fdopen returned null!\n");
    perror("fdopen");
    return -1;
  }
  int res = fread(buf, sizeof(char), 256, fp);

  printf("fread returned %d\n", res);

  puts(buf);

  res = fclose(fp);
  printf("fclose() returned %d\n", res);

  return 0;

}
