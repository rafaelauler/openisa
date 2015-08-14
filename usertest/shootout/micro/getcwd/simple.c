#include <unistd.h>

int
main(int argc, char **argv) {
  char buf[1024];
  getcwd(buf, 1024);
  puts(buf);
}
