#include <stdio.h>

void function() {
	char text[40];

	printf("Enter your name: ");
	scanf("%s", &text);
	printf("Hello => %s, Initial => %c, Second => %c \n", text, text[0], text[1]);
}

int main() {
	function();
	getchar();
	return 0;
}