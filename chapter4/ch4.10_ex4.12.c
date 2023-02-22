#include <stdio.h>
#define MAX 100

// Упр. 4.12 
// Рекурсивная версия itoa

void itoa(char s[], int n);

int main (void) {
	char s[MAX];
	int n = -123789;

	itoa(s, n);
	printf("%s\n", s);
	return 0;
}

void itoa(char s[], int n) {
	// статическая переменная для сохранения позиции в строке
	static int i = 0;
	
	// если число отрицательное, добавляем знак
	if (n < 0) {
		s[i++] = '-';
		n = -n;
	}

	// пока не 0 доходим до первой цифры
	if (n / 10) {
		itoa(s, n / 10);
	}
	
	// последовательно записываем в массив цифры
	s[i++] = n % 10 + '0';
	s[i] = '\0';
}
