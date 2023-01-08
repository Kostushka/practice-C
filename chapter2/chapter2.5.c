#include <stdio.h>
// 2.5 Арифметические операции
// + - * / %
// % - не применима к float и double

int main (void) {

    int x; // год

    if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0) {
        printf("%d leap year", x);
    } else {
        printf("%d not leap year", x);
    }

    return 0;
}