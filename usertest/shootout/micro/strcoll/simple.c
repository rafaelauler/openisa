#include <string.h>
#include <stdio.h>

int main() {
  char buf[256], buf2[256];
  printf("Digite duas palavras.\n");
  scanf("%s %s", buf, buf2);
  printf("\nstrcoll() retorna %d\n", strcoll(buf, buf2));
}
