#include <stdio.h>

void function() {
	char c;
	short s;
	int i;
	float f;
	double d;

	c = 'a';
	s = 8;
	i = 50;
	f = 3.14;
	d = 0.00005;
	
	printf("c = %d | ", sizeof(c) );
	printf("s = %d | ", sizeof(s) );
	printf("i= %d | ", sizeof(i) );
	printf("f = %d | ", sizeof(f) );
	printf("d = %d | ", sizeof(d) );

}

int main() {
	function();
	getchar();
	return 0;
}