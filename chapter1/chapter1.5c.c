#include <stdio.h>

// 1.5.3 Подсчет строк

int main (void) {

    int c, nl;
    nl = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') { // символ конца строки в потоке
            ++nl;
        }
    }
    printf("nl: %d", nl);

    return 0;
}