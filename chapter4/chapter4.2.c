#include <stdio.h>
#include <ctype.h>

// 4.2 Функции, возвращающие нецелые значения
// atof - преобразует строку в число типа double
// "42.5\0" => 4 -> 2 -> 5 -> 425 / 10 -> 42.5

double atof (char s[]);

int main (void) {
    char s[] = "42.55";
    printf("%f\n", atof(s));
    return 0;
}

double atof (char s[]) {
    double pow, res;
    int i, flag, count, sign;

    for (i = 0; isspace(s[i]); i++); // Убираем пробелы слева

    sign = 1;

    // Записываю знак
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        ++i;
    }

    res = flag = count = 0;

    // Записываю все число и считаю в k кол-во цифр после точки
    while (s[i] != '\0') {
        if (s[i] == '.') {
            flag = 1;
            ++i;
            continue;
        }
        if (flag) {
            ++count;
        }
        res = res * 10 + (s[i] - '0');
        ++i;
    }
    // возвожу 10 в степень k
    pow = 1;
    while (count-- > 0) {
        pow = pow * 10;
    }
    return sign * res / pow;
}