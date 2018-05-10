#include <stdio.h>
void write_real_number(float n) {
	printf("%4.2f", n);
}
int main(int argc, const char* argv[]) {
	float real_number = 5.1;
	write_real_number(real_number);
	getchar();
	return 0;
}