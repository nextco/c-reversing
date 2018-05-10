#include <stdio.h>

void function() {
	char c = 'n';
	int i = (int)c;

	printf("%d\n", i);
}

int main() {
	function();
	getchar();
	return 0;
}