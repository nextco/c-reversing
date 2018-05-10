/*
Solución ejercicio 14 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>
#include <string.h>

int main(int argc, const char* argv[]) {
	// define the data type for dynamic
	struct People {
		char name[300];		// bytes = 300, Check the stack finding the missing value of _age // 00401334 add eax, 304 | 004012E7 add eax, 304
		unsigned int age;	// bytes = 4
		char email[252];	// bytes = 252 => 556 - (300+4)									  // 004012FE mov [esp+268h+Dest], 556 ; Size		
	};

	// 004012C3 mov[esp + 268h + _ptr_peoples], offset _f_name; "Juan el Viejo\n"
	struct People people_static;
	// setting values
	strcpy(people_static.name, "Juan el Viejo");	// Removed the ugly format (EOL) for clarify
	strcpy(people_static.email, "juan@mail.me");
	people_static.age = 200;


	// dynamic
	struct People *people_dynamic;		// 004012FE mov [esp+268h+_ptr_struct], 556	
	people_dynamic = (struct People*) malloc(sizeof(struct People));

	strcpy(people_dynamic->name, "Pedrito");
	strcpy(people_dynamic->email, "pedrito@mail.me");
	people_dynamic->age = 21;

	// print values - a litle bit different for clarify
	printf("people_static.name = %s\n", people_static.name);
	printf("people_static.email = %s\n", people_static.email);
	printf("people_static.age = %d\n", people_static.age);

	printf("people_dynamic.name = %s\n", people_dynamic -> name);
	printf("people_dynamic.email = %s\n", people_dynamic -> email);
	printf("people_dynamic.age = %d\n", people_dynamic -> age);
	
	
	free(people_dynamic);		// 004013BE call _free	
	getchar();					// 004013C3
	return 0;
}