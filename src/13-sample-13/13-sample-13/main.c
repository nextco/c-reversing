/*
Solución ejercicio 13 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/

#include <stdio.h>
void swap(int *a, int *b) {
	int auxiliar = (*a);		// 00401296 mov eax, [ebp + _ptr_a]
								// mov eax, [eax]
								// mov[ebp + _auxiliar], eax
	
	(*a) = (*b);				// 0040129E mov edx, [ebp+_ptr_a]
								// mov eax, [ebp + _ptr_b]
								// mov eax, [eax]
								// mov [edx], eax
	
	(*b) = auxiliar;			// 004012A8 mov edx, [ebp+_ptr_b]
								// mov eax, [ebp + _auxiliar]
								// mov[edx], eax	
}

int main(int argc, const char* argv[]) {
	int a = 5;					// 004012DC mov[ebp + _a], 5
	int b = 12;					// 004012E3 mov[ebp + _b], 12
	
	swap(&a, &b);				// 004012F7 call _intercambia
	printf("Now a = %d and b = %d\n", a, b);
	
	getchar();					// 00401316 call    _getchar	
	return 0;					// Not in code but good practice
}