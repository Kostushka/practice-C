#include <stdio.h>

// Упр. 3.5
// Функция, которая преобразовывает целое число в символную строку в системе счисления с основанием b
// учет знака
// 25 -> 25 % b = 9 -> 25 / b % b = 1 -> 25 / b == 0
// '91'
// '19'
void itob (int n, char s[], int b);
int getNum(int n);
void reverse (char s[]);

int main (void) {

    int a, b;
    char s[10];
    a = 26;
    b = 16;

    itob(a, s, b);
    printf("%s\n", s);

    return 0;
}

void itob (int n, char s[], int b) {
    int sign, i;
    // учли знак
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;
    // остаток от деления == символ
    // делим, пока число > 0
    do {
        // s[i++] = n % b + '0';
        s[i++] = getNum(n % b);
    } while ((n /= b) > 0);

    // записываем знак, если он есть
    if (sign < 0) {
        s[i++] = '-';
    }

    s[i] = '\0';

    reverse(s);
}

void reverse (char s[]) {
    int i, j, c, lenght;

    for (lenght = 0; s[lenght] != '\0'; lenght++);

    for (i = 0, j = lenght - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }

}

int getNum(int n) {
	if (n >= 10) {
		// 58 + 7 = 65
		return n + '0' + 7;
	}
	return n + '0'; 
}
