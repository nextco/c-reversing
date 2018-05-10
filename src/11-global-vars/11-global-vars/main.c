#include <stdio.h>
int number;
int resultado;

int square(int n) {
	return n * n;
}

int main(int argc, const char* argv[]) {
	number = 5;
	resultado = square(number);
	printf("square of number is %d", resultado);
	printf(" | square of 3 is %d", square(3));
	getchar();
	return 0;
}