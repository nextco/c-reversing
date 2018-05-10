#include <stdio.h>
int number;
int resultado;

int square() {
	printf("square of number is %d", number * number);	
}

int main(int argc, const char* argv[]) {
	number = 5;
	square(number);
	getchar();
	return 0;
}