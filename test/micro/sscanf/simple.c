#include <stdio.h>
#include <string.h>

int
main(int argc, char **argv) {
  char str[1024];
  if (argc == 1) {  
    scanf("%s", str);
  } else {
    strncpy(str, argv[1], 1024);
  }
  int var1 = 0;
  char var2 = 0;
  sscanf(str, "%ld%c", &var1, &var2);
  printf("You typed the nums %d and char '%c'.\n", var1, var2);
}
