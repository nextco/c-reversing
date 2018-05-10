#include <stdio.h>

void function() {
	int counter = 0;  // mov[ebp + _counter], 0
	for (counter = 0; counter <= 10; counter++) {
		if (counter == 5) {
			continue;
		}
		printf("%d ", counter);
	}
}

int main() {
	function();
	return 0;
}