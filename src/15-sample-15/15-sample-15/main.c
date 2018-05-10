/*
Solución ejercicio 15 del curso de C y Reversing de Ricardo Narvaja.
by @rextco
*/
#include <stdio.h>
#include <string.h>

// Linked list
struct s {	
	int value;			// 4 bytes
	struct s* next;		// 4 bytes next address
};

void print_linked_list(struct s *first) {
	if (first != NULL) {										// 004012C2 cmp[ebp + _ptr_first_linked_list], 0
																// 004012C6 jz short locret_4012EB
		// printf("*linked_list \t\t = %x\n", (unsigned int)first);
		// printf("linked_list.value \t = %d\n", first->value);
		// printf("linked_list.next \t = %x\n\n", (unsigned int)(first->next));
		printf("%d\n", first->value);							// 004012C8 mov eax, [ebp+_ptr_first_linked_list]
																// 004012CB mov eax, [eax]
																// 004012CD mov[esp + 8 + var_4], eax
																// 004012D1 mov[esp + 8 + Format], offset Format; "%d\n"
																// 004012D8 call _printf
																
		print_linked_list(first->next);							// 004012DD mov eax, [ebp + _ptr_first_linked_list]
																// 004012E0 mov eax, [eax + 4]
																// 004012E3 mov[esp + 8 + Format], eax; ptr_first_linked_list
																// 004012E6 call _MuestraLista
		
	}
}

// 00401290
struct s* create_element(int value) {
	struct s* element = (struct s*) malloc(sizeof(struct s));	// 004012A2 mov [ebp+_element], eax
	element->value = value;										// 004012AB mov [edx], eax
	element->next = NULL;										// 004012B0 mov dword ptr [eax+4], 0
	return element;
}

// pass pointer by reference to change parent value from function (parent = element)
void insert_element(struct s** parent, int value) {
	// int get_referenced_value = (*parent)->value;
	// printf("get_referenced_value % d", get_referenced_value);

	struct s* element;
		
	if ( (*parent) != NULL) {										// 004012FF jz short _is_null_parent		
		// printf("(*parent)->value => %d\n", (*parent)->value);
		// printf("(*parent) => %d, (*parent) = %x\n", (*parent), (unsigned int) (*parent));
		// printf("parent != NULL => %d\n\n", value);
				
		if ( (*parent) -> value < value) {							// 00401309 jge short loc_401322
			// printf("(*parent)->value => %d\n", (*parent)->value);
			// printf("(*parent) = %x, parent = %x\n", (unsigned int) (*parent), (unsigned int)parent);
			
			struct s ** element_ = (struct s **)(*parent) + 1;		// 0040130B mov eax, [ebp+_value]
																	// 0040130E mov[esp + 18h + _copy_of_value], eax
																	// 00401312 mov eax, [ebp + _ptr_of_parent]
																	// 00401315 add eax, 4 <= not 4 because add 16
																	// 00401318 mov[esp + 18h + element], eax
																	// 0040131B call _InsertarLista
			// printf("element = %x\n", (unsigned int)(element));			
			insert_element(element_, value);

		}else {
			element = create_element(value);					// 00401322 mov eax, [ebp + _value]
																// 00401325 mov[esp + 18h + element], eax
																// 00401328 call _CrearLista
																// 0040132D mov[ebp + _new_internal_linked_list], eax

			element -> next = (*parent);						// 00401330 mov edx, [ebp+_new_internal_linked_list]
																// 00401333 mov eax, [ebp+_ptr_of_parent]
																// 00401336 mov[edx + 4], eax

			// printf("\ndebug: insert_element\n");
			// print_linked_list(element);
																			
			(*parent) = element;								// 00401339 mov edx, [ebp + _copy_of_ptr_to_parent]
																// 0040133C mov eax, [ebp + _new_internal_linked_list]
																// 0040133F mov[edx], eax <= a litle tricky

			// printf("\ndebug: random\n");
			// print_linked_list(*parent);
		}
	}
	else {														// 00401343 _is_null_parent
		// printf("parent == NULL => %d", value);
		// create_element
		element = create_element(value);						// 00401343 mov eax, [ebp + _value]
																// 00401346   mov[esp + 18h + element], eax
																// call _CrearLista
																// 0040134E mov[ebp + _new_internal_linked_list], eax

		(*parent) = element;									// 00401351 mov edx, [ebp + _copy_of_ptr_to_parent]
																// 00401354 mov eax, [ebp + _new_internal_linked_list]
																// 00401357 mov[edx], eax
	}
	
}



int main(int argc, const char* argv[]) {

	struct s* linked_list = create_element(5);		// 00401385 mov [esp+18h+_value], 5 ; value
													// call _CrearLista
													// 00401391 mov [ebp+_linked_list], eax
	// printf("debug: create_element\n");
	// print_linked_list(linked_list);												
	
	
	insert_element(&linked_list, 3);				// 00401394 mov [esp+18h+_param_value_for_insert], 3 ; param
													// 0040139C lea eax, [ebp + _linked_list]; pointer by reference
													// 0040139F mov[esp + 18h + _value], eax
													// 004013A2 call _InsertaLista
	
	
	// printf("\ndebug: insert_element 3\n");
	// print_linked_list(linked_list);

	
	insert_element(&linked_list, 2);				// 004013A7
	// printf("\ndebug: insert_element 2\n");
	// print_linked_list(linked_list);
	
	insert_element(&linked_list, 6);				// 004013BA
	// printf("\ndebug: insert_element 6\n");
			
	/*
	// Some random test code
	insert_element(&linked_list, 1);
	insert_element(&linked_list, 50);
	insert_element(&linked_list, 20);
	insert_element(&linked_list, 300);
	insert_element(&linked_list, 8000);
	insert_element(&linked_list, 0);	
	insert_element(&linked_list, -30);
	insert_element(&linked_list, -800);
	insert_element(&linked_list, 100000);			// LGFM
	*/
	

	
	print_linked_list(linked_list);					// 004013CD mov eax, [ebp+_linked_list]
													// 004013D0 mov[esp + 18h + _value], eax
													// 004013D3 call _MuestraLista
		
	getchar();										// 004013D8
	getchar();										// 004013DD
	return 0;										// 004013E2
}