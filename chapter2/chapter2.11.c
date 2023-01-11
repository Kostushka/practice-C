#include <stdio.h>

// 2.11 Условные выражения

int main (void) {
    int a, b, z;
    a = 2;
    b = 5;
    z = 0;

    z = (a > b) ? a : b; 

    printf("%d\n", z);

    return 0;
}