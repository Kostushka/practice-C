#include <stdio.h>

// 1.5 Символьный ввод-вывод

int main (void) {

    char c;
    char a = 'a';
    char b = 'b';

    // Символьный ввод: getchar() - функция для получения символа из входного потока
    c = getchar(); // получаем символ из потока ввода и записываем в переменную
    printf("c: %c\n", c);

    // Символьный вывод: putchar(c) - функция, которая выводит один символ
    putchar(c);
    putchar(a);
    putchar(a);
    putchar(b);
    putchar('f');

    return 0;
}