#include <stdio.h>
#include <time.h>

int
main() {
  char c;
  time_t time1 = time(0);
  printf("time(0) = %d\n", time1);
  struct tm *tm = gmtime(&time1);
  if (tm == NULL) {
    printf("gmtime() returned NULL.\n");
    return -1;
  }

  printf("tm_sec = %d\n", tm->tm_sec);
  printf("tm_min = %d\n", tm->tm_min);
  printf("tm_hour = %d\n", tm->tm_hour);
  printf("tm_mday = %d\n", tm->tm_mday);
  printf("tm_mon = %d\n", tm->tm_mon);
  printf("tm_year = %d\n", tm->tm_year);
  printf("tm_wday = %d\n", tm->tm_wday);
  printf("tm_yday = %d\n", tm->tm_yday);
  printf("tm_isdst = %d\n", tm->tm_isdst);

}
