#include <stdio.h>

void function() {
	int number;
	
	printf("Input a number: ");
	scanf("%d", &number);
	if (number > 0) {
		printf("Positive number");
	}
	else {
		printf("Negative number");
	}
}

int main() {
	function();
	getchar();
	return 0;
}