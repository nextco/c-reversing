#include <stdio.h>
void function() {
	FILE* f;
	char file_name[80] = "prueba.txt";	// 004012CF mov eax, dword ptr ds:_filename_ptr ; "prueba.txt"
	f = fopen(file_name, "rt");			// 00401310 mov [esp+0D8h+Val], offset Mode ; "rt"

	if (f == NULL) {
		printf("File not exist!\n");
		exit(1);
	}

	char line[96];			// stack view => 000000C8 _buffer db 96 dup(?)
	while (!feof(f)) {
		fgets(line, 80, f);	// 0040135B mov [esp+0D8h+Val], 50h ; MaxCount
		puts(line);
	}
	fclose(f);
}
int main(int argc , const char* argv[]) {
	function();
	getchar();
	return 0;
}