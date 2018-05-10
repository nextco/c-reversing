#include <stdio.h>

void function() {
	char input_letter;

	printf("Input a letter: ");
	scanf("%c", &input_letter);

	switch (input_letter){
		case ' ':
			printf("Space");
			break;
		case '0': case '1':case '2':case '3':case '4':case '5':case '6':case '7':case '8':case '9':
			printf("Digit");
			break;
		default:
			printf("No space or digit");
			break;
	}	
}

int main() {
	function();
	return 0;
}