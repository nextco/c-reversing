// Equivalente
#include <stdio.h>
#include <string.h>

void function() {
	char text_1[56];
	char text_2[48];
	int comparator;

	puts("Enter a word: ");
	gets(text_1); // Siempre se pasa por referencia

	puts("Enter another word: ");
	gets(text_2); 

	comparator = strcmp(text_1, text_2);
	if (comparator == 0) {
		printf("Equals\n");
	}
	else if (comparator > 0) {
		printf("First word is big\n");
	}
	else {
		printf("Second word is big\n");
	}
}

int main() {
	function();
	getchar();
	return 0;
}