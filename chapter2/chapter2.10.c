#include <stdio.h>

// 2.10 Операции с присваиванием
// + - * / << >> & | ^

// Подсчитывает единицы в двоичной записи
int bitcount (unsigned x);

int main (void) {

    int num = 0b1111;

    printf("%d\n", bitcount(num));

    return 0;
}

int bitcount (unsigned x) {

    int count;
        
    count = 0;
    
    while (x != 0) {
        if (x & 01) {
            ++count;
        }
        x >>= 1;
    }

    return count;
}