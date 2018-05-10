/*
Solución Práctica #1 - Lección 19 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>

int main(int argc, const char* argv[]) {
	int min_hours_formal_worker = 35;		// 004012BA mov[ebp + _min_hours_formal_worker], 35		
	int price_per_hour = 12;				// 004012C1 mov[ebp + _price_per_hour], 12
	int price_bonification = 22;			// 004012C8 mov[ebp + _price_bonification], 22
	
	int salary;
	int worked_hours;
	char input_exit_condition;

	do {
		printf("worked hours => ");
		scanf("%d", &worked_hours);

		if (worked_hours <= 35) {
			salary = worked_hours * price_per_hour;					// 004012F4 mov eax, [ebp + _horas_trabajadas]
																	// 004012F7 imul eax, [ebp + _price_per_hour]
																	// 004012FB mov[ebp + _salario]
		}else {			

																	// 00401300 mov eax, [ebp + _min_hours_formal_worker]
																	// 00401303 mov ecx, eax
			// ecx = min_hours_formal_worker * price_per_hour;							// 00401305 imul ecx, [ebp + _price_per_hour]

																	// 00401309 mov edx, [ebp + _min_hours_formal_worker]
																	// 0040130C mov eax, [ebp + _horas_trabajadas]
			// eax = (worked_hours - min_hours_formal_worker) * price_bonification;		// 0040130F sub eax, edx
																	// 00401311 imul eax, [ebp + _price_bonification]
																	// 00401315 lea eax, [ecx + eax]
			// eax = ecx + eax										// 00401318 mov[ebp + _salario], eax
			salary = (min_hours_formal_worker * price_per_hour) + (worked_hours - min_hours_formal_worker) * price_bonification;
		}

		printf("=> Salary = %d euros\n\n", salary);
		fflush(stdin);												// 0040132E mov eax, ds:__imp___iob <= clean the input buffer
																	// 00401333 mov[esp + 28h + _format_for_printf], eax; File
																	// 00401336 call _fflush
		printf("[+] want to calculate another salary (y/n)? \n");
		scanf(" %c", &input_exit_condition);						// 00401347 lea eax, [ebp+_input_letter] <= note the space before %c
																	// 0040134A mov[esp + 28h + var_24], eax
																	// 0040134E mov[esp + 28h + _format_for_printf], offset aC; "%c"
																	// 00401355 call _scanf
		// printf("input_exit_condition %c", input_exit_condition);


	} while (input_exit_condition != 'N' && input_exit_condition != 'n' );	// 0040135A cmp [ebp+_input_letter], 'S' <= Logic fixed here y=yes, n=no
																			// 0040135E jz short _end_program
	
	return 0;	// Not in code but good practice
}