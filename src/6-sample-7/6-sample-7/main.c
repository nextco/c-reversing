#include <stdio.h>
// float32 = float
// float64 = double

void function() {	
	double double_number;
	int integer_div;
	float float_div;
	int integer_a;
	int integer_b;
	
	integer_a = 7;
	integer_b = 5;
	float_div = (float)((double)7 / (double)5);
	double_number = (double)float_div;
	printf("%f\n", double_number);

	integer_div = integer_a / integer_b;	
	double_number = (double)integer_div;
	printf("%f\n", double_number);
}

int main() {
	function();
	getchar();
	return 0;
}