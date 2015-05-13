#include <stdio.h>

int
main(int argc, char **argv) {
  char var = 0;
  FILE *fp = fopen("testcase.txt", "r");
  fscanf(fp, "%c", &var);
  fprintf(stdout, "testcase.txt's first char is '%c'.\n", var);
  rewind(fp);
  var = 0;
  fscanf(fp, "%c", &var);
  fprintf(stdout, "I ran rewind. Now testcase.txt's first char is '%c'.\n", var);
  fclose(fp);
}
