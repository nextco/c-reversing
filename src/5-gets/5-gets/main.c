#include <stdio.h>

void function() {
	char text[40];

	puts("Enter your name: ");
	gets(text); // Siempre se pasa por referencia
	printf("Hello => %s\n", text);
}

int main() {
	function();
	getchar();
	return 0;
}