#include <stdio.h>
// 2.6 Операции отношения и логичекие операции

// Операции отношения:
// > >= < <=

// Операции сравнения
// != ==

// Логические операции 
// && || - приоритет ниже, чем у операций отношения и сравнения

// 1 - истинно
// 0 - ложно

// if (!valid) == if (valid == 0)

// 2.2 Цикл эквивалентный for, но без && ||
int main (void) {

    int i, c;
    char s[10];
    int lim = 10;

    // for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; i++) {
    //     s[i] = c;
    //     printf("1.%c", s[i]);
    // }

    for (i = 0; i < lim - 1; i++) {
        if ((c = getchar()) != EOF) {
            if (c != '\n') {
                s[i] = c;
                printf("2.%c", s[i]);
            } else {
                break;
            }
        } else {
            break;
        }
    }

    return 0;
}