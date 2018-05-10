#include <stdio.h>

void function() {
	float f = 5.25;
	int i = (int)f;
	printf("%d\n", i);
}

int main() {
	function();
	getchar();
	return 0;
}