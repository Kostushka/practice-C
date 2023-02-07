#include <stdio.h>
#include <stdlib.h>

// 7.8.7 Генерирование случайных чисел
// rand() - вычисляет последовательность случайных целых чисел от 0 до RAND_MAX
// srand(unsigned) - устанавливает для rand инциализирующее значение

// случайные числа от 0 до 1
#define frand() ((double) rand() / (RAND_MAX + 1.0))

int main (void) {
	double x;
	for (int i = 0; i < 10; i++) {
		printf("%.2g\n", x = frand());
	}
	return 0;
}
