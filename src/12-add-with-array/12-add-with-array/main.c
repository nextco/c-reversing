#include <stdio.h>

void add(int a, int b) { 
	
}

int main(int argc, const char* argv[]) {
	int data[100];
	int quantity_numbers;
	long add = 0;
	
	do{
		printf("Quantity of numbers to add?: \n");
		scanf("%d", &quantity_numbers);
		if (quantity_numbers > 100) {
			printf("Error: MAX_QUANTITY = 100 \n");
			// exit(-1);
		}
	} while (quantity_numbers > 100);

	// Get number values
	int i;
	for (i = 0; i < quantity_numbers; i++){
		printf("Enter %d number value?: ", i);
		scanf("%d", &data[i]);
	}
	
	// Add
	for (i = 0; i < quantity_numbers; i++) {
		add += data[i];
	}	

	printf("The addition of numbers is = %ld", add);
	getch();
	return 0;
}