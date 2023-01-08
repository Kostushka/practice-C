#include <stdio.h>
#define LOW 0
#define HIGH 300
#define STEP 20

// 1.4 Символические константы

int main (void) {

    int fahr;

    printf("Fahr\tCelsius\n");

    // Цикл for с символическими константами для лучшей читаемости
    for (fahr = LOW; fahr <= HIGH; fahr = fahr + STEP) {
        printf("%3d\t%6.1f\n", fahr, 5.0 / 9.0 * (fahr - 32));
    }

    return 0;
}