#include <stdio.h>
#include <string.h>

int
main(int argc, char **argv) {
  char *region1 = "blablablalbkreljdklafjds;kflj";
  char *region2 = "blablablalkjs;lkfjas;dljfa;js";
  char *region3 = "blablablalbkreljdklafjds;kflj";
  printf("memcmp(region1, region2, 29) = %d\nmemcmp(region1, region3, 29) = %d\n",
         memcmp(region1, region2, 29),
         memcmp(region1, region3, 29));
}
