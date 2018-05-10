#include <stdio.h>

void add_function() {
	int a = 0;
	int b = 0;
	int add = 0;
	
	printf("First number: ");
	scanf("%d", &a);

	printf("Second number: ");
	scanf("%d", &b);

	add = a + b;

	printf("The addition is %d", add);
}

int main() {
	add_function();
	getchar();
	return 0;
}