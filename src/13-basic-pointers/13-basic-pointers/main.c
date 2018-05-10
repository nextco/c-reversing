#include <stdio.h>

int main(int argc, const char* argv[]) {
	int *ptr;
	ptr = (int *)malloc(sizeof(int));
	*(ptr) = 3;


	printf("Address of ptr = %x\n", (unsigned int)ptr);
	printf("Value = %d\n", (*ptr) );

	(*ptr)++;
	printf("Address of ptr = %x\n", (unsigned int)ptr);
	printf("Value = %d\n", (*ptr));
		
	getch();
	return 0;
}