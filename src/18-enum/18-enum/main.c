#include <stdio.h>
enum days{	
	lunes,		// 0
	martes,		// 1
	miercoles,	// 2
	jueves,		// 3
	viernes,	// 4	
	sabado,		// 5
	domingo,	// 6
	extra = 0xFFFFFFFF
};
int main(int argc, const char* argv[]) {
	enum days day_x;
	day_x = sabado;
	printf("day_x = sabado =>  %x\n", day_x);

	enum days fiesta = sabado;
	enum days dormir = domingo;
	printf("fiesta =>  %x\n", fiesta);
	printf("dormir =>  %x\n", dormir);

	enum days extra_day = extra;
	printf("extra_day =>  %d\n", extra_day);

	getch();
	return 0;
}