#include <stdio.h>

void function() {
	int a;
	signed int b;
	unsigned int c;

	a = -1;
	b = -2;
	c = 2147483650;

	printf("a = %d | ", a);
	printf("b = %d | ", b);
	printf("c = %u ", c);
}

int main() {
	function();
	getchar();
	return 0;
}