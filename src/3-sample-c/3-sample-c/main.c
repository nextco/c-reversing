#include <stdio.h>

void function() {
	int i;
	int j;

	for (i = 0; i <= 5; i++) {	//  jg short _exit_loop
		for (j = 0; j <= 20; j += 2){
			if (i == 1) {	//  cmp     [ebp+counter_i], 1 | jnz short _body_loop_interno 
				if (j > 6) { //  cmp     [ebp+counter_j], 6 | jle short _body_loop_interno
					goto exit_loop;
				}							
			}
			printf("i = %d | j = %d \n", i, j);
		}
	}

	exit_loop:
		printf("Fin del programa!\n");
}

int main() {
	function();
	getchar();
	return 0;
}