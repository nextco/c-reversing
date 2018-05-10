#include <stdio.h>

void function() {
	char input_letter;

	printf("Donde nacio?: \n");
	printf("1 => Argentina\n");
	printf("2 => Puerto Rico\n");
	printf("3 => Colombia\n");
	printf("4 => Uruguay\n");

	scanf("%c", &input_letter);

	switch (input_letter) {
	case '1':
		printf("Choice => Argentina");
		break;
	case '2':
		printf("Choice => Puerto Rico");
		break;
	case '3':
		printf("Choice => Colombia");
		break;
	case '4':
		printf("Choice => Uruguay");
		break;

	default:
		printf("Invalid country");
		break;
	}
}

int main() {
	function();
	return 0;
}