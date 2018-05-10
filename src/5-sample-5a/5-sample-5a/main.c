// Tal cual
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
	if (!(comparator == 0)) {
		if (comparator <= 0){
			printf("Second word is big\n");
		}
		else {
			printf("First word is big\n");
		}
	}
	else {
		printf("Equals\n");
	}
}

int main() {
	function();
	getchar();
	return 0;
}