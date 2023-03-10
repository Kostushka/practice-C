#include <stdio.h>
#include <math.h>

// 7.8.6 Математические функции

int main (void) {
	// принимаю и возвращают тип double
	double x = 5, y = 2;
	
	// синус х в радианах
	sin(x);
	
	// косинус х в радианах
	cos(x);
	
	// арктангенс y/x в радианах
	atan2(y, x);
	
	// экспоненциальная функция (е в степени х)
	exp(x);
	
	// натуральный логарифм х
	log(x);
	
	// десятичный логарифм х
	log10(x);
	
	// x в степени y
	pow(x, y);
	
	// квадратный корень из x
	sqrt(x);
	
	// абсолютное значение х
	fabs(x);
	
	return 0;
}
