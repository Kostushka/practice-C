#include <stdio.h>

// 3.4 Оператор switch

/*
switch (выражение) {
    case целочисл.-конст: 
        операторы;
    case целочисл.-конст: 
        операторы;
    default: 
        операторы;
}
*/

// Подсчет цифр, пробельных символов и других символов через switch

int main (void) {

    char digitsCount[10];
    int i, c, whitespaceCount, othercCount;

    for (i = 0; i < 10; i++) {
        digitsCount[i] = 0;
    }

    whitespaceCount = othercCount = 0;

    while ((c = getchar()) != EOF) {
        switch (c) {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                ++digitsCount[c - '0'];
                break;
            case ' ':
            case '\t':
            case '\n':
                ++whitespaceCount;
                break;
            default:
                ++othercCount;
                break;
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%i: %d\n", i, digitsCount[i]);
    }
    printf("white space: %d\n", whitespaceCount);
    printf("other: %d\n", othercCount);


    return 0;
}