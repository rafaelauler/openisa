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
  if (strcmp(str, "haha") == 0) {
    printf("You typed haha.\n");
  } else
    printf("You didn't type haha.\n");
}
