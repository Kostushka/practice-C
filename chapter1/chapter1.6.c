#include <stdio.h>

// 1.6 Массивы

// Программа, которая подсчитывает 
// 1) количество каждой цифры: 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 
// 2) количество пробельных символов (\n, \t, ' ')
// 3) количество всех остальных символов

int main (void) {

    // блок объявления
    int c, i;
    int ndigit[10]; // ndigit[0] ... ndigit[9] [ , , , , , , , , , ]
    int nwhite, nother;

    // блок инициализации
    for (i = 0; i < 10; ++i) {
        ndigit[i] = 0; // [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
    }
    nwhite = nother = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            // printf("c = %d; '0' = %d; c - '0' = %d\n", c, '0', c - '0');
            ++ndigit[c - '0']; // инкремент счетчика цифры [0, 0, 0, 1, 0, 0, 0, 0, 0, 0]
            // так как с == int: c = 48; '0' = 48; c - '0' = 0
            // c = 52; '0' = 48; c - '0' = 4
            // c = 50; '0' = 48; c - '0' = 2
        } else if (c == ' ' || c == '\t' || c == '\n') {
            ++nwhite; // инкремент пробельных символов
        } else {
            ++nother; // инкремент других символов
        }
    }

    printf("ndigit: ");
    for (i = 0; i < 10; i++) {
        printf("%d: %d, ", i, ndigit[i]);
    }
    printf("nwhite: %d, nother: %d\n", nwhite, nother);

    return 0;
}
