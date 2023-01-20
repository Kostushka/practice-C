#include <stdio.h>

// 4.10 Рекурсия

// 125 => 125 % 10 => 5 
// 125 / 10 > 0 => 12 % 10 => 2
// 12 / 10 > 0 => 1 % 10 => 1
// 1 / 10 = 0
// "521\0" -> reverse() -> "125\0"  

// выводим десятичные цифры
void printd (int num);

int main (void) {

	printd(125);
	printf("\n");
	
	return 0;
}

void printd (int num) {
	// если отрицательное число, выводим знак, работаем как с положительным
	if (num < 0) {
		putchar('-');
		num = -num;
	}

	if (num / 10) {
		// рекурсивно доходим до num / 10 = 0
		printd(num / 10);
	}
	// выполняется, когда дошли до первого символа
	putchar(num % 10 + '0');
}

/*
do {
	s[i++] = num % 10 + '0';
} while ((num / 10) > 0);
*/