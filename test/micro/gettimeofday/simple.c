#include <stdio.h>
#include <time.h>
#include <sys/time.h>

int
main(int argc, char **argv) {
  struct timeval tv;

  /* Use of timezone argument is obsolete, should be NULL.
     See POSIX1-2008.*/
  int result = gettimeofday(&tv, NULL);

  printf("gettimeofday returned %d\n", result);
  printf("timeval struct: \t{ tv_sec = %d\n\t\t  tv_usec=%d }\n", tv.tv_sec,
         tv.tv_usec);

  return 0;
}
