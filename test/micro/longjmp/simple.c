#include <setjmp.h>

sigjmp_buf jmpenv;

int aux() {
  siglongjmp(jmpenv, 1);
}

int
main(int argc, char **argv) {
  printf("Hello\n");
  if (sigsetjmp(jmpenv,0)) {
    printf("returning from siglongjmp\n");
    return 0;
  }
  aux();
}
