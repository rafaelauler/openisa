#include <stdio.h>
#include <ctype.h>

int
main() {
  char mychar = 'C', mychar2 = 'c';
  printf("isupper(C) = %d\n", isupper(mychar));
  printf("isspace(C) = %d\n", isspace(mychar));
  printf("isprint(C) = %d\n", isprint(mychar));
  printf("tolower(C) = %c\n", tolower(mychar));
  printf("toupper(c) = %c\n", toupper(mychar2));
}
