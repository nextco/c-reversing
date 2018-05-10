/*
Solución ejercicio 16 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>

int main(int argc, const char* argv[]) {
	int variable, i, r_not, r_or, r_shl, r_sar;		// r_or => result of or operation
	
	for (i = 1; i <= 10; i++){
		variable = 55;								// 004012C7 mov [ebp+_variable], 55
		printf("variable = %d\n", variable);
		r_not = ~variable;							// 004012E1 mov eax, [ebp + _variable]
													// 004012E4 not eax
													// 004012E6 mov[ebp + _r_not], eax
		
		r_or = i | variable;						// 004012E9 mov eax, [ebp+_counter]
													// 004012EC or eax, [ebp + _variable]
													// 004012EF mov[ebp + _r_or], eax
												
		printf("result is = %d %d\n", r_not, r_or); // 004012F2 mov eax, [ebp+_r_or]
													// 004012F5 mov[esp + 58h + _param_printf_1], eax
													// 004012F9 mov eax, [ebp + _r_not]
													// 004012FC mov[esp + 58h + _param_printf_0], eax
													// 00401300 mov[esp + 58h + _print_format], offset aElResultadoEsD; "  El resultado es: %d %d\n"
													// call _printf
		
		r_shl = r_or << (i & 0xFF);					// 0040130C mov ecx, [ebp+_counter]
													// 0040130F mov eax, [ebp + _r_or]
													// 00401312 shl eax, cl <= cl is 8 bits size
													// 00401314 mov [ebp+_r_shl], eax
		
		// printf("r_shl %x \n", r_shl);
		r_sar = (r_shl >> 3) & 0xFFFFFFFF;			// 00401317 mov eax, [ebp+_r_shl]
													// 0040131A sar eax, 3
													// 0040131D mov[ebp + _r_sar], eax <= eax is 32 bits size
		
		printf("result is = %d %d\n\n", r_shl, r_sar);// 00401320 mov eax, [ebp+_r_sar] <= added extra EOL
													// 00401323 mov[esp + 58h + _param_printf_1], eax
													// 00401327 mov eax, [ebp + _r_shl]
													// 0040132A mov[esp + 58h + _param_printf_0], eax
													// 0040132E mov[esp + 58h + _print_format], offset aElResultadoEsD; "  El resultado es: %d %d\n"
													// 00401335 call _printf
	}

	getchar();										// 00401341
	return 0;										// 00401346
}