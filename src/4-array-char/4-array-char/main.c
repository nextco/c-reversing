#include <stdio.h>

void function() {
	char text[40];
	
	printf("Enter your name: ");
	scanf("%s", &text);
	printf("Hello > %s\n", text);
}

int main() {
	function();
	getchar();
	return 0;
}