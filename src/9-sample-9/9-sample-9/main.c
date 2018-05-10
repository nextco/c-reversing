#include <stdio.h>
#include <string.h>
void function() {

	struct File {
		char name[44];	// 44 bytes
		int size;		// 4 bytes
	}file[1000];
	
	// struct File file[1000];

	int counter_file = 0;
	int option = 0;
	
	int i; // counter_i for case_2 | 004013E5     mov     eax, ds:_i
	int buffer_integer;
	char buffer_input[48];
	
	printf("===> Practice - Ejemplo # 9 - Curso C y Reversing");
	do{		
		printf("\n\n<< Enter a option(int): \n");
		printf("1. Add file\n");
		printf("2. Show files (all)\n");
		printf("3. Show files(by min_size condition)\n");
		printf("4. Show file(by name)\n");
		printf("5. Exit\n");
		
		// Wait for user input
		gets(buffer_input);				// 0x00401309
		sscanf(buffer_input, "%d", &option);

		// printf("debug | option = %d ", option);

		// char random[15];
		switch (option){
		case 1:
			if (counter_file <= 999) {
				printf("Enter file name : =>");
				gets(file[counter_file].name);
				
				printf("Enter size (Kb) : =>");
				gets(buffer_input);				// 0x004013BA
				sscanf(buffer_input, "%ld", &file[counter_file].size);
				// printf("debug | counter_file = %d | name = %s | size = %d\n ", counter_file, file[counter_file].name, file[counter_file].size);
				counter_file++;				
			}else {
				printf("Max files reached (1000)!\n");
			}
			break;

		case 2:	// 2. Show files (all)
			for (i = 0; i < counter_file; i++){
				printf("name: %s | size: %ld Kb\n", file[i].name, file[i].size);
			}
			break;
		case 3: // 3. Show files(by min_size condition)
			printf("Enter minimum size of file to show => :");
			gets(buffer_input);				// 0040144E     call    _gets
			sscanf(buffer_input, "%ld", &buffer_integer);

			for (i = 0; i < counter_file; i++) {				
				if (file[i].size >= buffer_integer) { //004014A5     jb      short _continue
					printf("name: %s | size: %ld Kb\n", file[i].name, file[i].size);
				}				
			}
			break;
		case 4: // 4. Show file(by name)
			printf("Details: Enter file name => ");
			gets(buffer_input);
			
			for (i = 0; i < counter_file; i++) {
				if ( strcmp( file[i].name, buffer_input) == 0 ) {
					printf("name: %s | size: %ld Kb\n", file[i].name, file[i].size);
				}
			}
			break;

		case 5:
			printf("=> Program end\n");
			break;

		default:
			printf("=> Unknown option!\n");
			break;
		}

	} while (option != 5);


}

int main() {
	function();
	// getchar();
	return 0;
}