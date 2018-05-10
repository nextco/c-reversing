#include <stdio.h>

void function() {
	int i = 0;
	for (i = 0; i != 10; i++){
		printf("%d ", i);
	}
}

int main() {
	function();
	return 0;
}