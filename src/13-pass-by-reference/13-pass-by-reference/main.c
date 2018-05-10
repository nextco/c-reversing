#include <stdio.h>
void duplicate(int *x){
	(*x) = (*x) * 2;
}

int main(int argc, const char* argv[]) {
	int number = 5;
	
	printf("Value  of number = %d\n", number);
	duplicate(&number); // pass by reference
	printf("Value  of number = %d\n", number);

	getch();
	return 0;
}