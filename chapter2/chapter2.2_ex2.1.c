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
    "long unsigned: %ld\n"
    "float: %.2e - %.2e\n"
    "double: %.2e - %.2e\n", CHAR_MIN, CHAR_MAX, UCHAR_MAX, 
    						 SHRT_MIN, SHRT_MAX, USHRT_MAX, 
    						 INT_MIN, INT_MAX, UINT_MAX, 
    						 LONG_MIN, LONG_MAX, ULONG_MAX, 
    						 FLT_MIN, FLT_MAX,
    						 DBL_MIN, DBL_MAX);

    return 0;
}
