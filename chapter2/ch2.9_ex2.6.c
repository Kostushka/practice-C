#include <stdio.h>

// Упр. 2.6 
// Функция setbits(x, p, n, y) - вернуть х, в котором n битов, начиная с позиции p, равны n крайним битам y
// остальные биты не тронуты

// (х, 4, 3, y)
//    43210
// х: 01100
// у: 00001
// 	  00100

// x >> (p + 1 - n)
//    65432
// x: 00011 обнулить n
//    00000 &
// y: 00001

int setbits(x, p, n, y);

int main(void) {

	
	
	return 0;
}

int setbits(x, p, n, y) {
	int copy_x = x;
	copy_x >> (p + 1 - n));
	copy_x = copy_x & (~0 << n);
	y 
	copy_x = copy_x & y;
	
}
