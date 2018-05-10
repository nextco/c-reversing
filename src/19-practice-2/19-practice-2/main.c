/*
Solución Práctica #2 - Lección 19 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>

int main(int argc, const char* argv[]) {
	int size_of_pyramid, counter_0, counter_1;
	printf("size of pyramid => ");												// 004012C6 lea eax, [ebp+_size_of_pyramid]
	scanf("%d", &size_of_pyramid);												// 004012C9 mov[esp + 18h + var_14], eax
																				// 004012CD mov[esp + 18h + _format_for_printf], offset aD; "%d"
																				// 004012D4 call _scanf

																				// 3 bucles <= open *.idb for clarify
	for (counter_0 = 1; counter_0 <= size_of_pyramid; counter_0++) {				// 004012D9 mov [ebp+_counter_0], 1
																					// 004012E0 _loop_0:
																					// 004012E0 mov eax, [ebp + _counter_0]
																					// 004012E3 cmp eax, [ebp + _size_of_pyramid]
																					// 004012E6 jg short _end_program

																					// printf("size_of_pyramid - counter_0 => %d\n", size_of_pyramid - counter_0);		
		for (counter_1 = 1; counter_1 <= (size_of_pyramid - counter_0); counter_1++) {	// 004012E8 mov [ebp+_counter_1], 1
																						// 004012EF _loop_1 :
																						// 004012EF mov eax, [ebp + _counter_0]
																						// 004012F2 mov edx, [ebp + _size_of_pyramid]
																						// 004012F5 sub edx, eax
																						// 004012F7 mov eax, edx
																						// 004012F9 cmp eax, [ebp + _counter_1]
																						// 004012FC jl short loc_401311

			printf(" ");																// 004012FE mov [esp+18h+_format_for_printf], offset asc_40301B ; " "
																						// 00401305 call _printf
																						// 0040130A lea eax, [ebp + _counter_1]
																						// 0040130D inc dword ptr[eax]
																						// 0040130F jmp short _loop_1
		}

		for (counter_1 = 1; counter_1 <= (2 * counter_0 - 1); counter_1++) {				// 00401311 mov [ebp+_counter_1], 1
																							// 00401318 _loop_2 :
																							// 00401318 mov eax, [ebp + _counter_0]
																							// 0040131B add eax, eax
																							// 0040131D dec eax
																							// 0040131E cmp eax, [ebp + _counter_1]
																							// 00401321 jl short loc_401336

			printf("*");																// 00401323 mov [esp+18h+_format_for_printf], offset asc_40301D ; "*"
																						// 0040132A call _printf
																						// 0040132F lea eax, [ebp + _counter_1]
																						// 00401332 inc dword ptr[eax]
																						// 00401334 jmp short _loop_2
		}

		printf("\n");																	// 00401336 loc_401336 : ; "\n"
																						// 00401336 mov[esp + 18h + _format_for_printf], offset asc_40301F
																						// 0040133D call _printf
																						// 00401342 lea eax, [ebp + _counter_0]
																						// 00401345 inc dword ptr[eax]
																						// 00401347 jmp short _loop_0
	}

	getch();	// Not in code, just for debug on Visual Studio
	return 0;	// Not in code but good practice
}