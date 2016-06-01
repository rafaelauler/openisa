#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>

int
main(int argc, char **argv) {
  struct rlimit rlim;
  int result = getrlimit(RLIMIT_DATA, &rlim);

  printf("getrlimit() returned %d\n", result);

  printf("struct rlimit {\trlim_cur = %u\t\trlim_max=%u }\n",
         rlim.rlim_cur, rlim.rlim_max);

  if (result != 0)
    return result;

  rlim.rlim_cur = 100000;
  result = setrlimit(RLIMIT_DATA, &rlim);

  printf("setrlimit() returned %d\n", result);

  if (result != 0)
    return result;

  result = getrlimit(RLIMIT_DATA, &rlim);
  printf("second call to getrlimit() returned %d\n", result);

  printf("struct rlimit {\trlim_cur = %u\t\trlim_max=%u }\n",
         rlim.rlim_cur, rlim.rlim_max);

  return 0;
}
