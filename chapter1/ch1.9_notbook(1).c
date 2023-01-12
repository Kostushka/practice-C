#include <stdio.h>

// Программа вывода длины строки входного потока, если длина более 80 символов

int main (void) {

    int c, i;
    i = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            ++i;
        }
        // 1.
        if (c == '\n') {
            // 2.
            if (i > 80) {
                printf("%d\n", i);
            }
            i = 0;
        }
       
    }

    return 0;
}