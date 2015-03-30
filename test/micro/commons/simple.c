#include <stdio.h>
#include <math.h>

char MyStringBuf[1024];
char MyOtherStringBuf[1024];

int
main() {
  char localBuf[1024];

  MyStringBuf[0] = '\0';
  MyOtherStringBuf[0] = '\0';
  printf("Type in word: ");
  scanf("%s", localBuf);
  strncpy(MyStringBuf, localBuf, 1024);
  printf("MyStringBuf[0] = %d\n", MyStringBuf[0]);
  printf("MyOtherStringBuf[0] = %d\n", MyOtherStringBuf[0]);
}
