#include <stdio.h>

// Упр. 3.6
// Функция преобразует целое число в строку символов, третий аргумент - минимальная ширина поля
// при необходимости добавлять пробелы слева от числа
// w = 6, n = 25
// '    25'

void itoa (int n, char s[], int w); 

void reverse (char s[]);


int main (void) {

    int a, w;
    a = 25;
    w = 6;
    char s[10];

    itoa(a, s, w);
    printf("%s\n", s);
    itoa(255555, s, w);
    printf("%s\n", s);
    itoa(2, s, w);
    printf("%s\n", s);


    return 0;
}

void itoa (int n, char s[], int w) {

    int sign, i, whiteCount;

    // учет знака
    if ((sign = n) < 0) {
        n = -n;
    }

    i = 0;

    // запись символов
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    // добавление знака
    if (sign < 0) {
        s[i++] = '-';
    }

    // считаем кол-во пробелов с учетом ширины поля
    whiteCount = w - i;
    // записываем пробелы
    while (whiteCount > 0) {
        s[i++] = ' ';
        --whiteCount;
    }

    s[i] = '\0';

    reverse(s);

}

void reverse (char s[]) {
    
    int i, j, c, length;

    for (length = 0; s[length] != '\0'; length++);

    for (i = 0, j = length - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}