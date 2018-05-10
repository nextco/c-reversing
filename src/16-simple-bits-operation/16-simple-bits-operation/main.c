#include <stdio.h>

int main(int argc, const char* argv[]) {
	int a = 67;
	int b = 33;
	printf("a = %x\n", a);
	printf("b = %x\n\n", b);
	printf("~a = %d\n", ~a);
	printf("a & b = %x\n", a & b);
	printf("a | b = %x\n", a | b);
	printf("a ^ b = %x\n", a ^ b);
	printf("a << 1 = %x\n", a << 1);
	printf("a >> 1 = %x\n", a >> 1);

	getchar();
	return 0;
}