#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
	// define the data type
	struct People {
		char name[30];
		char email[25];
		int age;
	};

	// dynamic
	struct People *peoples;
	int quantity_of_people = 2;
	peoples = (struct People*) malloc( quantity_of_people * sizeof(struct People) );
	

	// setting values
	strcpy(peoples -> name, "@nextco");
	strcpy(peoples -> email, "nextco@mail.me");
	peoples -> age = 18;

	strcpy( (peoples + 1) -> name, "@reversing");
	strcpy( (peoples + 1) -> email, "re@mail.me");
	(peoples + 1) -> age = 33;

	int i;
	for (i = 0; i < quantity_of_people; i++){
		printf("peoples.name = %s\n", (peoples + i) -> name);	// Just add the struct offset for every element
		printf("peoples.email = %s\n", (peoples + i)-> email);
		printf("peoples.age = %d\n", (peoples + i) -> age);
	}

	free(peoples);
	getchar();
	return 0;
}