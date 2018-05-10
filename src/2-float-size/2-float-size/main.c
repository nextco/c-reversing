#include <stdio.h>

void function() {
	float f;
	long float lf;
	
	double d;
	long double ld;

	f = 3.14f;
	lf = 0.0000123;

	d = 1.141523232;
	ld = 0.0000000000000000123;

	printf("f = %f | ", f);
	printf("uf = %f | ", lf);
	printf("d = %f | ", d);
	printf("ld = %f ", ld);

}

int main() {
	function();
	getchar();
	return 0;
}