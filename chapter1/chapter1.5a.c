#include <stdio.h>

// 1.5.1 Копирование входного потока в выходной поток по одному символу

int main (void) {

    int c; // int - так как значение EOF (конец файла) - целое число из stdio.h - не является типом char 

    printf("%d\n", getchar() != EOF); // символ != концу файла ? 1 : 0
                                      // Enter - тоже символ; EOF - не символ
    while ((c = getchar()) != EOF) {
        putchar(c);
        printf("|c: %d|\n", c);
        printf("|EOF: %d|", EOF);
    }

    return 0;
}