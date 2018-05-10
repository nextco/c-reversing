#include <stdio.h>

void add(int a, int b) { // 00401328 - 0040134B
	int r;
	r = a + b;
	printf("The value of addition is %d\n\n", r);
}

void compare(int a, int b) {
	if (a == b) { // 00401358 jnz short loc_401368
		printf("both params are equals\n\n");		
	}else if (a > b) { // A litle trick to clarify code
		printf("a value is greater of b\n\n");
	}else {
		printf("b value is greater of a\n\n");
	}
}

int main(int argc, const char* argv[]) {
	int a, b;
	printf("Enter a value: \n");
	scanf("%d", &a);
	
	printf("Enter b value: \n");
	scanf("%d", &b);
	
	add(a, b);
	compare(a, b);

	getch();

	return 0;
}