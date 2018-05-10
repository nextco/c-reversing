#include <stdio.h>

void function() {
	//2 * 10 = 20 dwords 20*4 = 80 bytes
	int matrix[2][10] =	{	1,2,3,4,5,6,7,8,9,10,
							11,12,13,14,15,16,17,18,19,20
						};

	int group = 1;	// 0, 1
	int id_student = 2; // => 13
	printf("Group = %d | id_student = %d | note = %d \n", group, id_student, matrix[group][id_student]);
}

int main() {
	function();
	getchar();
	return 0;
}