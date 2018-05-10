#include <stdio.h>

void function() {
	int add = 0;
	int array_[5] = {30,31,32,33,34};
	
	int i;
	for (int i = 0; i < 5; i++){
		add += array_[i];
	}
	printf("Addition = %d\n", add);

}

int main() {
	function();
	getchar();
	return 0;
}