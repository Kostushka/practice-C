#include <stdio.h>

//1.3 Цикл for

// Программа перевода температур F => С
int main (void) {
    // объявление переменных
    int farh;

    // заголовок
    printf("Farh\tCelsius\n");

    // цикл for от 0 до 300
    for (farh = 0; farh <= 300;  farh = farh + 20) {
        printf("%3d\t%6.1f\n", farh, 5.0 / 9.0 * (farh - 32.0));
    }

    // заголовок
    printf("Farh\tCelsius\n");

    // цикл for от 300 до 0
    for (farh = 300; farh >= 0;  farh = farh - 20) {
        printf("%3d\t%6.1f\n", farh, 5.0 / 9.0 * (farh - 32.0));
    }

    return 0;
}