#include <stdio.h>

// Упр. 2.8
// rightrot - возвращает значение своего целого аргумента x после его вращения вправо на n двоичных разрядов

int rightrot(unsigned short x, int n);

int main(void) {
	// 0000 0000 0000 1011 2
	// 1100 0000 0000 0010
	//    c    0    0    2
	unsigned short int x = 013;

	printf("%x\n", rightrot(x, 2));
	
	return 0;
}

int rightrot(unsigned short x, int n) {
	// 00000101
	// >> 1
	// 00000010
	// 1 << bit_size
	// 10000000
	// |
	// 00000010
	// 10000000
	// --------
	// 10000010

	// вычисляю количество битов в числе для сдвига крайнего бита
	int bit_size = sizeof(x) * 8;

	while (n-- > 0) {
		// нахожу последний бит
		int last_bit = x & 01;
	
		// сдвигаю вправо на 1 бит
		x >>= 1;
	
		// если последний бит = 1, добавляю 1 в самый высокий разряд числа
		if (last_bit) {
			x |= (01 << (bit_size - 1)); // x | 10000000
		} 
	} 
	
	return x;
}
