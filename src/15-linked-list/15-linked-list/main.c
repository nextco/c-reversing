#include <stdio.h>
#include <string.h>

// Linked list
struct s {
	char name[30];		// 30 bytes
	char address[50];	// 50 bytes
	int age;			// 4 bytes
	struct s* next;		// 4 bytes next address
};

// Global vars
struct s* linked_list_0;
struct s* linked_list_1;
struct s* linked_list_2;

void print_linked_list(struct s *first) {
	if (first != NULL) {
		// print values - a litle bit different for clarify
		printf("*linked_list \t\t = %x\n", (unsigned int)first);
		printf("linked_list.name \t = %s\n", first -> name);
		printf("linked_list.address \t = %s\n", first ->address);
		printf("linked_list.age \t = %d\n\n", first -> age);
		print_linked_list(first->next); // show next
	}
}

int main(int argc, const char* argv[]) {
	// Define first 
	linked_list_0 = (struct s*) malloc(sizeof(struct s));		
	strcpy(linked_list_0 -> name, "Peter");
	strcpy(linked_list_0 -> address, "Jr. Localhost");
	linked_list_0 -> age = 10;
	linked_list_0 -> next = NULL; // No more
			
	linked_list_1 = (struct s*) malloc(sizeof(struct s));
	strcpy(linked_list_1->name, "George");
	strcpy(linked_list_1->address, "Jr. Ratata");
	linked_list_1->age = 12;
	linked_list_1->next = NULL;
	
	// Linking
	linked_list_0->next = linked_list_1;
	

	// Insert a third element between two inserted values
	struct s* linked_list_2;
	linked_list_2 = (struct s*) malloc(sizeof(struct s));
	strcpy(linked_list_2->name, "Norma");
	strcpy(linked_list_2->address, "Jr. Trio");
	linked_list_2->age = 21;
	linked_list_2->next = NULL;
	
	// Linking 0 - 2 - 1
	linked_list_0 -> next = linked_list_2;
	linked_list_2 -> next = linked_list_1;
	
	printf("debug: print_linked_list => insertion\n");
	print_linked_list(linked_list_0);

	// Remove third element
	linked_list_0->next = linked_list_1;
	free(linked_list_2);
	printf("\ndebug: print_linked_list => delete\n");
	print_linked_list(linked_list_0);

	free(linked_list_0);
	free(linked_list_1);
	getchar();
	return 0;
}