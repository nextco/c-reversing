#include <stdio.h>
int square(int n) {
	return n * n;
}

int main(int argc, const char* argv[]) {
	int number;
	int resultado;

	number = 5;
	resultado = square(number);
	printf("square of number is %d", resultado);
	printf(" | square of 3 is %d", square(3));
	getchar();
	return 0;
}