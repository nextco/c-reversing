#include <stdio.h>

void function() {
	char text[40];

	printf("Enter your name: ");
	scanf("%s", &text);
	printf("Hello => %s, Initial => %c\n", text, text[0]);
}

int main() {
	function();
	getchar();
	return 0;
}