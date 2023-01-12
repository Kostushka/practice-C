#include <stdio.h>
#define HIGH 300
#define LOW 0
#define STEP 20

// Упр. 1.15
// Программа преобразования температур с помощью функции

// Прототип функции
float conversionTempToF (int c);

// Прототип функции
float conversionTempToC (int f);

int main (void) {

    int celsius;
    int fahr = LOW;

    printf("C => F\n");
    for (celsius = LOW; celsius <= HIGH; celsius = celsius + STEP) {
        printf("|%d|: %.1f\n", celsius, conversionTempToF(celsius));
    }

    printf("F => C\n");
    while (fahr <= HIGH) {
        printf("|%d|: %.1f\n", fahr, conversionTempToC(fahr));
        fahr = fahr + STEP;
    }


    return 0;
}

// Определение функции: C => F
float conversionTempToF (int celsius) {
    // объявление
    float fahr;
    // инициализация значением вычисления
    fahr = celsius * (9.0 / 5.0) + 32.0;
    // возврат значения в Фаренгейтах
    return fahr;
}

// Определение функции: F => C
float conversionTempToC (int fahr) {
    // объявление
    float celsius;
    // инициализация значением вычисления
    celsius = 5.0 / 9.0 * (fahr - 32.0);
    // возврат значения в Цельсия
    return celsius;
}