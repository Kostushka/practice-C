#include <stdio.h>

// 3.6 Циклы do while
/*
do
    оператор;
while (выраж);
*/
// Функция преобразует целое число в строку символов
// 25 -> 5 -> '5' -> 2 -> '2' -> '52'
void itoa (int n, char s[]);

void reverse (char s[]);

int main (void) {

    int a = -25;
    char s[10];

    itoa(a, s);
    printf("%s\n", s);


    return 0;
}

void itoa (int n, char s[]) {
    int i, sign;

    // учет знака, делаем число положительным
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;

    // записываем символы числа в массив в обратном порядке
    do {
        s[i++] = n % 10 + '0'; 
    } while ((n /= 10) > 0);

    // записываем знак
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