/*
Solución ejercicio 12 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>

int main(int argc, const char* argv[]) {
	/*
	float* ptr_float_a = (float *)malloc( sizeof(float));
	*(ptr_float_a) = 5.0f;

	float* ptr_float_b = (float *)malloc( sizeof(float) );
	*(ptr_float_b) = 6.7f;
	*/

	// Prefered - Simplified version i think
	float float_a = 5.0f;
	float* ptr_float_a = &float_a;
	
	float float_b = 6.7f;
	float* ptr_float_b = &float_b;
	

	printf("Prefixed value for add are => %4.2f \n", *(ptr_float_a) + *(ptr_float_b) );	
	printf("Your turn: Enter first value: \n");
	scanf("%f", ptr_float_a);

	printf("Your turn: Enter second value: \n");
	scanf("%f", ptr_float_b);
	

	printf("Updated add is => %4.2f", *(ptr_float_a) + *(ptr_float_b));
	free(ptr_float_a);
	free(ptr_float_b);	
	
	// getchar();	
	// getchar();
	// getchar();
	getch(); // Just fix the three ugly getchar()
	return 0; // Not in code but good practice
}