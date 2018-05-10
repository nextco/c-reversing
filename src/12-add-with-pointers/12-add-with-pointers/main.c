#include <stdio.h>

int main(int argc, const char* argv[]) {
	int* data;
	int quantity_numbers;
	long add = 0;

	do {
		printf("Quantity of numbers to add?: \n");
		scanf("%d", &quantity_numbers);
		data = (int *)malloc(quantity_numbers * sizeof(int));
		if (data == NULL) {
			printf("Error: No space on memory\n");
		}
	} while (data == NULL);

	// Get number values
	int i;
	for (i = 0; i < quantity_numbers; i++) {
		printf("Enter %d number value?: ", i);
		scanf("%d", data + i);
	}

	// Add
	for (i = 0; i < quantity_numbers; i++) {
		add += *(data + i);
	}

	printf("The addition of numbers is = %ld", add);
	free(data);
	getch();
	return 0;
}