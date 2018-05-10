#include <stdio.h>

int main(int argc, const char* argv[]) {
	int data[10];
	int i;

	// data[0] = 5;
	printf("data = %x\n", (unsigned int)data);
	// printf("data[0] = %x\n", data);
	// printf("data[1] = %x\n", data + 1);
	// printf("data[2] = %x\n", data + 2);

	for (i = 0; i < 10; i++) {
		*(data + i) = i * 2; // 0, 2, 4, 6, 8, ... , 2k
	}

	for (i = 0; i < 10; i++) {
		printf("value = %d | data = %x\n", *(data + i), (unsigned int)(data + i));
	}

	getchar();
	return 0;
}