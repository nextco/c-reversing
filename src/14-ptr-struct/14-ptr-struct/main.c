#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
	// define the data type
	struct People {
		char name[30];
		char email[25];
		int age;
	};

	// first people are static
	struct People people_1;

	// setting values
	strcpy(people_1.name, "@nextco");
	strcpy(people_1.email, "maro@mail.me");
	people_1.age =  18;

	printf("people_1.name = %s\n", people_1.name);
	printf("people_1.email = %s\n", people_1.email);
	printf("people_1.age = %d\n", people_1.age);

	getchar();
	return 0;
}