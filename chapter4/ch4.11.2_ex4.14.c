#include <stdio.h>
#define swap(t, x, y) {t c; c = x; x = y; y = c;}

// Упр. 4.14
// Макрос swap обменивает местами значения двух аргументов типа t

int main (void) {
	int x, y;
	x = 5;
	y = 8;

	printf("%d %d\n", x, y);
	swap(int, x, y);
	printf("%d %d\n", x, y);
	
	return 0;
}
