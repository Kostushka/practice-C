#include <stdio.h>

// 4.8 Блочная структура
// С - не блочно-структурный язык, т.к. нельзя в функции определять функцию
// НО можно переменные в функции определять в блочно-структурном стиле {...}

int x;
int y;

int main (void) {

	int n, i;
	i = 25;
	n = 10;
	printf("i: %d\n", i);
	
	if (n > 0) {
		// i в блоке
		int i;
		for (i = 0; i < n; i++) {
			printf("i in if: %d\n", i);
		}
		printf("i in if: %d\n", i);
	}
	
	printf("i: %d\n", i - 10);
	
	return 0;
}

// переменные в блоке
void f (double x) {
	double y;
	printf("%g %g", x, y);
}
