/*
Solución Práctica #3 - Lección 19 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void write_array(char* ptr_array, int size) {// 00401432
	int i_;
	for (int i_ = 0; i_ < size; i_++){		// 00401438 mov[ebp + _i], 0
											// 0040143F _loop_print :
											// 0040143F mov eax, [ebp + _i]
											// 00401442 cmp eax, [ebp + _size]
											// 00401445 jge short _exit_loop

		printf("%c ", ptr_array[i_]);		// 00401447 mov eax, [ebp+_ptr_array]
											// 0040144A add eax, [ebp + _i]
											// 0040144D movsx eax, byte ptr[eax]
											// 00401450 mov[esp + 18h + var_14], eax
											// 00401454 mov[esp + 18h + Format], offset aC; "%c "
											// 0040145B call    _printf
												
											// 00401460 lea eax, [ebp + _i]
											// 00401463 inc dword ptr[eax]
											// 00401465 jmp short _loop_print
	}
	
	printf("\n");							// 00401467 _exit_loop: ; "\n"
											// 00401467 mov[esp + 18h + Format], offset asc_403032
											// 0040146E call _printf
	// return;
}

int main(int argc, const char* argv[]) {	
	srand(time(NULL));	

	int counter_0, counter_letter, counter_2, index;	
	char array_letras[26];					// from stack view & bucles to get size
	char random_letters[1000];

	index = 0;
	for (counter_0 = 65; counter_0 <= 90; counter_0++){
		array_letras[index++] = counter_0;
	}
	// write_array(array_letras, 26);

	index = 0;
	for (counter_0 = 0; counter_0 <= 999; counter_0++) {
		random_letters[index++] = array_letras[rand() % 26];		// Maybe not equal but equivalent
		// random_letters[index++] = rand() % 26 + 65;				// From IDA Hex-Rays

	}

	printf("The initial random array is:\n ");	
	write_array(random_letters, 1000);			// 00401374 mov [esp+448h+size], 1000 ; size
												// 0040137C lea eax, [ebp + ptr_array]
												// 00401382 mov[esp + 448h + _compiler_added_trash], eax; ptr_array
												// 00401385 call _escribirArray


	for (counter_0 = 0; counter_0 <= 25; counter_0++) {
		counter_letter = 0;

		for (counter_2 = 0; counter_2 <= 999; counter_2++){
			if (array_letras[counter_0] == random_letters[counter_2]) {
				counter_letter++;
			}
		}

		printf("The letter %c appears %d times\n", array_letras[counter_0], counter_letter);// 004013F8 _print_letter_counts:
		// printf("The letter %c appears %d times\n", counter_0 + 65, counter_letter);// 004013F8 _print_letter_counts:

																							// 004013F8 mov eax, [ebp + _counter_letter]
																							// 004013FE mov[esp + 448h + var_440], eax
																							// 00401402 mov eax, [ebp + _counter_0]
																							// 00401408 add eax, 41h
																							// 0040140B mov[esp + 448h + size], eax
																							// 0040140F mov[esp + 448h + _compiler_added_trash], offset aLaLetraCAparec; "La letra %c aparece %i veces\n"
																							// 00401416 call _printf
																							// 0040141B lea eax, [ebp + _counter_0]
																							// 00401421 inc dword ptr[eax]
																							// 00401423 jmp loc_401394
	}



	getch();	// 00401428 call _getch
	return 0;	// Not in code but good practice
}