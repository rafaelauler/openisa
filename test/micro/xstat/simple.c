
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int __xstat(int ver, const char * path, struct stat * stat_buf);

int
main() {
  struct stat StructStat;
  stat("/bin/ls", &StructStat);
  printf("i-node number for /bin/ls: %d\n", StructStat.st_size);
}
