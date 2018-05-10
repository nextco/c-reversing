#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void write_array(char* ptr_array, int size) {
	int i_;
	for (int i_ = 0; i_ < size; i_++) {	
		printf("%c ", ptr_array[i_]);
	}
	printf("\n");
}

int main(int argc, const char* argv[]) {
	srand(time(NULL));
	
	int i = 0;
	printf("rand() \n");
	for (i = 0; i < 100; i++) {
		printf("%d ", rand());
	}
	
	printf("\n\nrand() %% 10 \n");
	for (i = 0; i < 100; i++) {
		printf("%d ", rand() % 10);
	}
	
	printf("\n\nrand() %% 26 \n");
	for (i = 0; i < 100; i++) {
		printf("%d ", rand() % 26);
	}
	
	printf("\n\nrand() %% 10 \n");
	for (i = 0; i < 100; i++) {
		printf("%d ", rand() % 10);
	}	

	getch();
	return 0;
}