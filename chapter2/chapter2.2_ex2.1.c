#include <limits.h>
#include <stdio.h>
#include <float.h>
// 2.2 Типы данных и их размеры:
// Упр 2.1 Программа для определения диапазонов переменных типов char short int long float double - библиотечно и с помощью вычислений

// char, int, float, double

// short    int      long
//  16    16 || 32    32

// unsigned char      signed char
//    0 - 255         -128 - 127  

int main (void) {

    printf("char: %d - %d\n" 
    "char unsigned: %d\n"
    "short: %d - %d\n" 
    "short unsigned: %d\n"
    "int: %d - %d\n"
    "int unsigned: %u\n" 
    "long signed: %ld - %ld\n" 
    "long unsigned: %lu\n"
    "float: %.2e - %.2e\n"
    "double: %.2e - %.2e\n", CHAR_MIN, CHAR_MAX, UCHAR_MAX, 
    						 SHRT_MIN, SHRT_MAX, USHRT_MAX, 
    						 INT_MIN, INT_MAX, UINT_MAX, 
    						 LONG_MIN, LONG_MAX, ULONG_MAX, 
    						 FLT_MIN, FLT_MAX,
    						 DBL_MIN, DBL_MAX);

    unsigned short ush = ~0; // 1111 1111 1111 1111
    // short sh = 0x7fff; // 0111 1111 1111 1111
    // ush >> 1           // 0111 1111 1111 1111
    unsigned char uch = ~0; // 1111 1111
    // uch >> 1             // 0111 1111
    unsigned int uint = ~0; // 1111 1111 1111 1111 1111 1111 1111 1111
    // uint >> 1            // 0111 1111 1111 1111 1111 1111 1111 1111
    unsigned long luint = ~0; // 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111
    // luint >> 1             // 0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111

    printf("\nu sh: %d, sh: %d - %d\n", ush, (ush >> 1) - ush, ush >> 1);
    printf("u ch: %d, ch: %d - %d\n", uch, (uch >> 1) - uch, uch >> 1);
    printf("u int: %u, int: %d - %d\n", uint, (uint >> 1) - uint, uint >> 1);
    printf("u int: %lu, int: %ld - %ld\n", luint, (luint >> 1) - luint, luint >> 1);
    return 0;
}
