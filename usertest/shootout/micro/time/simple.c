#include <stdio.h>
#include <time.h>

int
main() {
  char c;
  time_t time1 = time(0);
  printf("time(0) = %d\n", time1);
  scanf("%c", &c);
  double theDiff = difftime(time(0), time1);
  printf("%d difftime = %lf\n", 0, theDiff);
}
