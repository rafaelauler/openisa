#include <stdio.h>

int
main() {
    int d;
    scanf("%d", &d);
    switch(d) {
	case 0:
	printf("You typed 0!\n");
	break;
	case 1:
	printf("You typed 1!\n");
	break;
	case 2:
	printf("You typed 2!\n");
	break;
	case 3:
	printf("You typed 3!\n");
	break;
	default:
	printf("You typed something else!\n");
	break;
    }
    printf("Hello world!\n");
}
