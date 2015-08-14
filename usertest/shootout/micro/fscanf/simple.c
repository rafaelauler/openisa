#include <stdio.h>

int
main(int argc, char **argv) {
  int var1 = 0;
  char var2 = 0;
  FILE *fp = fopen("testcase.txt", "r");
  fscanf(fp, "%d%c", &var1, &var2);
  fprintf(stdout, "testcase.txt contains the nums %d and char '%c'.\n", var1, var2);
  fclose(fp);
}
