#include <stdio.h>

// Программа вывода длины всех строк из входящего потока > 80 символов

int main (void) {

    int c, count;

    count = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' && count > 80) {
            printf("%d\n", count);
            count = 0;
        } else {
            ++count;
        }
    }

    return 0;
}