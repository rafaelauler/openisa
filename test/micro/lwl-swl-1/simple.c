#include <stdio.h>

#pragma pack(1)

typedef struct _MyStruct {
  short myShort;
  int myInt;
} MyStruct;

MyStruct S;

void doPrint() {
  printf("myShort = %d\nmyInt= %d\n", S.myShort, S.myInt);
}

main(int argc, char **argv) {
  S.myShort = 1000;
  S.myInt = 1000000 + argc;
  doPrint();
}
