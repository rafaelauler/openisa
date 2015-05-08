#include <stdio.h>

int
main() {
  char *mypath = getenv("BLBL");
  if (mypath == 0)
    printf("BLBL does not exist.\n");
  else
    printf("BLBL does exist. Error...\n ");
}
