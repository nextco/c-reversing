#include <stdio.h>
#define QUANTITY_OF_NUMBERS 5
int main(int argc, const char* argv[]) {
	// const int max_attempts = 5;
	int data[QUANTITY_OF_NUMBERS];
	int add = 0;
	int i;
	printf("QUANTITY_OF_NUMBERS = %d\n", QUANTITY_OF_NUMBERS);
	for (i = 0; i < QUANTITY_OF_NUMBERS; i++){
		printf("Enter %d number => ", i);
		scanf("%d", &data[i]);
	}

	for (i = 0; i < QUANTITY_OF_NUMBERS; i++) {
		add += data[i];
	}

	printf("The addition is =  %d\n", add);
	printf("The average is =  %4.2f\n", (float)add/QUANTITY_OF_NUMBERS );

	getch();
	return 0;
}