#include <stdio.h>

//1.2 Цикл while

// Программа перевода температур F => С 
int main(void) {
    // объявление
    float celsius, fahr;
    int low, high, step;

    // присвоение
    low = 0;
    high = 300;
    step = 20;
    fahr = low;

    // заголовок
    printf("Program to convert degrees Fahrenheit to degrees Celsius\n");
    printf("Fahr\tCelsius\n");

    // пока значение Фаренгейта меньше максимального значения
    while (fahr <= high) {
        celsius = 5.0 / 9.0 * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }

    return 0;
}