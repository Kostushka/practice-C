#include <stdio.h>

// Упр. 1.14
// Программа вывода гистограммы частот встречаемости в потоке разных символов

int main (void) {

    // объявление
    int c, i;
    int ndigit[10]; // цифры [ , , , , , , , , , ]
    int nwhite; // пробельные сиволы
    int nother; // остальные символы

    // инициализация
    for (i = 0; i < 10; i++) {
        ndigit[i] = 0; // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    }
    nwhite = nother = 0;

    // цикл для подсчета
    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            ++ndigit[c - '0'];
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite;
        } else {
            ++nother;
        }
    }

    printf("ndigit: ");
    for (i = 0; i < 10; i++) {
        printf("|%d|: %d, ", i, ndigit[i]);
    }
    printf("nwhite: %d, ", nwhite);
    printf("nother: %d\n", nother);

    // гисторграмма
    // цифры
    printf("ndigit: \n");
    for (i = 0; i < 10; i++) {
        printf("%d", i);
        while (ndigit[i]-- > 0) {
            printf("_");
        }
        printf("\n");
    }
    // пробельные символы
    printf("nwhite: ");
    for (i = 0; i < nwhite; i++) {
        printf("_");
    }
    printf("\n");
    // другие символы
    printf("nother: ");
    for (i = 0; i < nother; i++) {
        printf("_");
    }
    printf("\n");
    

    return 0;
}