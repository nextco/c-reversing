#include <stdio.h>
#include <string.h>

void function() {
	char text_1[40];
	char text_2[40];
	char text_3[40];

	puts("Enter a phrase: ");
	gets(text_1); // Siempre se pasa por referencia

	strcpy(text_2, text_1); // destination, source
	printf("\nstrcpy => %s", text_2);

	strncpy(text_3, text_1, 3); // Only 3 first letters
	text_3[3] = '\0'; // Evitar basura
	printf("\nstrncpy => %s", text_3);
}

int main() {
	function();
	getchar();
	return 0;
}