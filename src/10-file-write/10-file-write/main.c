#include <stdio.h>

void function() {
	FILE* f;
	f = fopen("text.file.dat", "wt");	// w = write, t=text
	fputs("Line 1: data 1\n", f);
	fputs("line 2: ", f);
	fputs(" data 2\n", f);
	fclose(f);
}

int main() {
	function();
	getchar();
	return 0;
}