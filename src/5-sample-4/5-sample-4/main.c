#include <stdio.h>
#include <string.h>

void function() {
	char text_1[56];
	char text_2[48];

	puts("Enter a word: ");
	gets(text_1); // Siempre se pasa por referencia

	puts("Enter another word: ");
	gets(text_2); // Siempre se pasa por referencia

	if (!(strcmp(text_1, text_2))) {
		printf("Equals\n");
	}else {
		printf("Not equals\n");
	}
}

int main() {
	function();
	getchar();
	return 0;
}