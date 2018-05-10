#include <stdio.h>

void function() {

	struct Student {
		char initial;
		int age;
		float average;
	}student[20]; // var_name
	student[1].initial = 'J';
	student[2].age = 20;
	student[11].average = 7.5;

	printf("x = %d | age = %d\n", 2, student[2].age);
}

int main() {
	function();
	getchar();
	return 0;
}