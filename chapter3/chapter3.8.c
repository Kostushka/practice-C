#include <stdio.h>

// Оператор goto и метки - выйти сразу из двух и более вложенных циклов
// лучше не использовать

int main (void) {

    int i, j;

    char s[] = "haha";
    char d[] = "bebeh";

    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; d[j] != '\0'; j++) {
            if (s[i] == d[j]) {
                goto found;
            }
        }
    }

    found: printf("%c\n", s[i]);

    return 0;
}