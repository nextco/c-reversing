#include <stdio.h>
struct bits {
	int bit_1 : 1;			// 1 bit
	int bits_2_to_5 : 4;	// 4 bit
	int bit_6 : 1;			// 1 bit	
	int bit_7_to_16 : 10;	// 10 bit => 16 bits == 2 bytes
};
int main(int argc, const char* argv[]) {
	struct bits custom_bits;
	custom_bits.bit_1 = 0b1;
	custom_bits.bits_2_to_5 = 0b0000;
	custom_bits.bit_6 = 0b1;
	custom_bits.bit_7_to_16 = 0b1111111111;
	
	// int  : 1;			// 1 bit
	// 16 bits trash | bit_7_to_16 - bit_6 - bits_2_to_5 - bit_1
	printf("custom_bits =>  %x\n", custom_bits); // Litle endian representation

	getch();
	return 0;
}