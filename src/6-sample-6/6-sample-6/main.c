#include <stdio.h>

void function() {
	char letter;
	int counter;

	counter = 97;
	while (counter <= 122) {
		letter = (char)counter;
		printf("%c ", letter);
		counter++;
	}
}

int main() {
	function();
	getchar();
	return 0;
}