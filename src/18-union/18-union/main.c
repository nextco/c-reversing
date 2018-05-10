#include <stdio.h>
union u{
	char letter;	// 1 byte
	int number;		// 4 bytes
};

int main(int argc, const char* argv[]) {
	union u custom_union;
	custom_union.number = 0xABCD1234;
	custom_union.letter = 0xDD;			// El primer byte pertener a letra
	// 0xabcd12dd => Porque esta en litle endian
	printf("custom_union.number =  %x\n", custom_union.number);

	getch();
	return 0;
}