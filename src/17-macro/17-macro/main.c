#include <stdio.h>
#define XOR_TWO_NUMBERS(x, y) x ^ y
int main(int argc, const char* argv[]) {
	int x, y;

	printf("Enter x value => \n");
	scanf("%d", &x);
	
	printf("Enter y value => \n");
	scanf("%d", &y);

	printf("x ^ y =  %d\n", XOR_TWO_NUMBERS(x,y) );

	getch();
	return 0;
}