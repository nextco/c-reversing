#include <stdio.h>

void function() {
	char input_letter;
	char target_letter;
	
	target_letter = 'n';
	
	printf("Input a letter: ");
	scanf("%c", &input_letter);

	printf("Input = %c | Target = %c ", input_letter, target_letter);

	getchar();
}

int main() {
	function();
	getchar();
	return 0;
}