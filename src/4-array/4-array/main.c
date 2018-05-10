#include <stdio.h>

void function() {
	int array_[5];
	int add;

	array_[0] = 30;
	array_[1] = 31;
	array_[2] = 32;
	array_[3] = 33;
	array_[4] = 34;

	add = array_[0] + array_[1] + array_[2] + array_[3] + array_[4];
	
	printf("Addition = %d | size = %d \n", add, sizeof(array_)/sizeof(int) );

}

int main() {
	function();
	getchar();
	return 0;
}