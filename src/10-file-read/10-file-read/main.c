#include <stdio.h>

void function() {
	FILE* f;
	char file_name[80] = "text.file.dat";
	f = fopen(file_name, "rt");	// r = read, t=text

	if (f == NULL) {
		printf("File not exist!\n");
		exit(1);
	}

	char line[81];
	fgets(line, 80, f);
	puts(line);
	fclose(f);
}

int main() {
	function();
	getchar();
	return 0;
}