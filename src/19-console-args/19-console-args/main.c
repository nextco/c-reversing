#include <stdio.h>

// argc => counter
// argv => pointer
int main(int argc, const char* argv[]) {
	int i;
	if (argc > 1) {
		printf("number of args =>  %d\n", argc);
		for (i = 0; i < argc; i++) {
			printf("args[%d] =>  %s\n", i, argv[i]);
		}
	}
	else {
		printf("enter args to debug\n");
	}

	getch();
	return 0;
}