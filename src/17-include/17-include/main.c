#include <stdio.h>
#include "c096.h"	// search on directory files

int main(int argc, const char* argv[]) {
	int x, y;

	printf("Enter x value => \n");
	scanf("%d", &x);

	printf("Enter y value => \n");
	scanf("%d", &y);

	printf("x ^ y =  %d\n", xor_two_numbers(x, y));

	getch();
	return 0;
}