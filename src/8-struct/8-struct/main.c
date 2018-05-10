#include <stdio.h>

void function() {

	struct Point3D{
		char tag;
		int x, y, z;
		float operation;
	}point; // var_name
	
	point.tag = 'p';
	point.x = 0;
	point.y = 5;
	point.z = 5;
	point.operation = 69.9;
	
	printf("x = %d | y = %d | z = %d | operation = %f\n", point.x, point.y, point.z, point.operation);
}

int main() {
	function();
	getchar();
	return 0;
}