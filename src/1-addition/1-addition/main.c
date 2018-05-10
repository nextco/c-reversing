#include <stdio.h>

void add_function() {
	int a = 234;
	int b = 567;
	int add = a + b;
	printf("The addition is %d", add);
}

int main() {
	add_function();
	getchar();
	return 0;
}