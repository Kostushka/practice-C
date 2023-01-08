#include <stdio.h>

// 1.7 Функции  
// Функция возведения в степень

// Прототип функции
int power (int m, int n);

// Главная функция программы
int main (void) {

    int i;
    // вызов функции power со степенью 0 - 9
    for (i = 0; i < 10; i++) {
        printf("|%d|: %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

// Определение функции
int power (int base, int n) {
    // объявление
    int i, p;
    // инициализация
    p = 1;
    // возведение в степень
    for (i = 1; i <= n; ++i) {
        p = p * base;
    }
    // возврат значения
    return p;
}