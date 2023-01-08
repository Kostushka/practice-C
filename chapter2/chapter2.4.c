#include <stdio.h>
// 2.4 Объявление
// все переменные должны быть объявлены до использования

int getsmth(const char []); // нельзя менять массив, переданный в функцию по адресу

int main (void) {

    int num = 25;
    char str2[] = "string";
    const int ch = '1'; // нельзя перезаписать
    const char str[] = "string"; // нельзя перезаписать элементы в массиве

    for (num = 0; num < 6; num++) {
        str2[num] = 'h';
    } 
    printf("%s\n", str);
    printf("%s\n", str2);

    return 0;
}


