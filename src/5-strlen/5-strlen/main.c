#include <stdio.h>

void function() {
	char text[40];

	puts("Enter your name: ");
	gets(text); // Siempre se pasa por referencia
	printf("Hello => %s\n", text);
	printf("Length => %d\n", strlen(text));
}

int main() {
	function();
	getchar();
	return 0;
}