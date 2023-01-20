#include <stdio.h>
#define swap(t, x, y) {t = x; x = y; y = t;}

// Упр. 4.14
// Макрос swap обменивает местами значения двух аргументов

int main (void) {
	int x, y, t;
	t = 0;
	x = 5;
	y = 8;

	printf("%d %d\n", x, y);
	swap(t, x, y);
	printf("%d %d\n", x, y);
	
	return 0;
}
