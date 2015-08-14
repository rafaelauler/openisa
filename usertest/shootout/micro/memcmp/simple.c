#include <stdio.h>
#include <string.h>

int
main(int argc, char **argv) {
  char region1[256], region2[256], region3[256];
  printf("Type string to fill region1\n");
  scanf("%s", region1);
  printf("Type string to fill region2\n");
  scanf("%s", region2);
  printf("Type string to fill region3\n");
  scanf("%s", region3);
  printf("memcmp(region1, region2, 29) = %d\nmemcmp(region1, region3, 29) = %d\n",
         memcmp(region1, region2, 29),
         memcmp(region1, region3, 29));
}
