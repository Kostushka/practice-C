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

    printf("char: %d - %d\n char unsigned: %d\n short: %d - %d\n short unsigned: %d\n int: %d - %d\n int unsigned: %d\n long signed: %d - %d\n long unsigned: %d\n", CHAR_MIN, CHAR_MAX, UCHAR_MAX, SHRT_MIN, SHRT_MAX, USHRT_MAX, INT_MIN, INT_MAX, UINT_MAX, LONG_MIN, LONG_MAX, ULONG_MAX);

    return 0;
}