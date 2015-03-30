#include <stdio.h>

int
main() {
  int mode;
  static const char *mode_names[4] = { "stereo", "j-stereo", "dual-ch", "single-ch" };
  printf("mode? [0 to 3] = ");
  scanf("%d", &mode);

  printf("mode = ");
  puts(mode_names[mode]);
}
