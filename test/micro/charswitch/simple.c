#include <stdio.h>

int
main(int argc, char **argv) {
  switch (argv[0][2]) {
  case 'c':
    printf("argv[0][2] = 'c'!\n");
    break;
  case 'd':
    printf("argv[0][2] = 'd'!\n");
    break;
  case 's':
    printf("argv[0][2] = 's'!\n");
    break;
  case 'i':
    printf("argv[0][2] = 'i'!\n");
    break;
  case 'a':
    printf("argv[0][2] = 'a'!\n");
    break;
  case 'b':
    printf("argv[0][2] = 'b'!\n");
    break;
  case 'e':
    printf("argv[0][2] = 'e'!\n");
    break;
  case 'f':
    printf("argv[0][2] = 'f'!\n");
    break;
  case 'g':
    printf("argv[0][2] = 'g'!\n");
    break;
  case 'z':
    printf("argv[0][2] = 'z'!\n");
    break;
  case 'l':
    printf("argv[0][2] = 'l'!\n");
    break;
  case 'm':
    printf("argv[0][2] = 'm'!\n");
    break;
  case 'n':
    printf("argv[0][2] = 'n'!\n");
    break;
  case 'o':
    printf("argv[0][2] = 'o'!\n");
    break;

  default:
    printf("I don't know which is the second char of this program name!\n");
    break;
  }
}
