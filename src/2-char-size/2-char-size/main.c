#include <stdio.h>

void function() {
	char c;
	short s;
	int i;

	c = 'n';
	s = -5;
	i = 0x123;

	printf("c = %d | ", c);
	printf("s = %d | ", s);
	printf("int = %d ", i);
}

int main() {
	function();
	getchar();
	return 0;
}