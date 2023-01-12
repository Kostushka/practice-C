#include <stdio.h>

// Упр 1.4 
// Программа перевода температур C => F
int main (void) {
    // объявление переменных
    float fahr, celsius;
    int low, high, step;

    // инициализация переменных значениями
    low = 0;
    high = 300;
    step = 20;
    celsius = 0;

    // заголовок
    printf("Program to convert degrees Celsius to degrees Fahrenheit\n");
    printf("Celsius\tFahrenheit\n");

    // вывод значений перевода, пока градусы Цельсия меньше максимального занчения
    while (celsius <= high) {
        fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%3.0f\t%6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }

    return 0;
}