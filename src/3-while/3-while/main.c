#include <stdio.h>

void function() {
	int number;

	do{
		printf("\nEnter a number? 0 (Zero) to exit: \n");
		scanf("%d", &number);
		
		if (number > 0) {
			printf("=> Negativo");
		}
		else {
			printf("=> Positivo");
		}

	} while (number != 0);

}

int main() {
	function();
	return 0;
}