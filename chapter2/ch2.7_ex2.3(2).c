#include <stdio.h>

// Упр. 2.3 (2)
// Программа, которая преобразует строку 16-чных цифр в число

/*
0xAF -> AF -> A * 16^1 + F * 16^0 -> 10 * 16 + 15 * 1 = 175
*/

// (строка) => 16чное число
int htoi(char s[]);

// (16чный символ) => 10чное число
int convert(char s);

// 16^n, где n = length - 1
int power(int a, int l);

int main (void) {

	char s[] = "0xFF";

	printf("%0X: ", htoi(s));
	printf("%d\n", htoi(s));
	
	return 0;
}

int htoi (char s[]) {

	int i, num, start, sLength, result;
	
	start = result = sLength = 0;

	// получаем длину строки
	for (i = 0; s[i] != '\0'; ++i) {
		++sLength; 
	}

	// учитываем наличие в строке обозначения 16чной системы
	if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
		start = 2;
		sLength = sLength - 2;

	}

	// каждый символ строки конвертируем в 10чное число, 
	// умножаем на 16 в степени разряда числа (от length - 1 по 0 включительно), 
	// прибавляем к итоговому результату
	for (i = start; (num = convert(s[i]))!= -1 ; ++i) {
		result = result + num * power(16, --sLength);
	}

	return result;
}

int convert(char s) {

	if (s >= '0' && s <= '9') {	
	
		// '0' - '0' -> 48 - 48 -> 0
		return s - '0';
		
	}
	
	if (s >= 'A' && s <= 'F') {
	
		// 'F' - 'A' + 10 -> 70 - 65 + 10 -> 15
 		return s - 'A' + 10;
		
	}

	if (s >= 'a' && s <= 'f') {

		// 'f' - ('a' - 'A') -> 102 - 32 -> 70 ('F')
		s = s - ('a' - 'A');
		// 70 - 65 + 10 -> 15
		return s - 'A' + 10;
		
	}
	
	return -1;
}

int power(int a, int length) {

	int res = 1;
	
	while (length > 0) {
		res = res * a;
		--length;
	}

	return res;
}
