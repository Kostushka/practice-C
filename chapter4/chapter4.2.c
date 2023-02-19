#include <stdio.h>
#include <ctype.h>
#define MAX 1000

// 4.2 Функции, возвращающие нецелые значения
// atof - преобразует строку в число типа double
// "42.5\0" => 4 -> 2 -> 5 -> 425 / 10 -> 42.5

// double atof (char s[]);
int atoi (char s[]);

// Примитивный калькулятор
int main (void) {
    // объявление функции в функции - нет прототипа
    double atof (char s[]);
    int myGetline (char s[]);
    double sum;

    char s[MAX];

    sum = 0;

    while (myGetline(s) > 0) {
        printf("str: %s\n", s);
        printf("sum: %g\n", sum += atof(s));
        printf("%d\n", atoi(s));
    }
    return 0;
}
// int main (void) {
//     char s[] = "42.55";
//     printf("%f\n", atof(s));
//     return 0;
// }

// atoi через atof
int atoi (char s[]) {
    double atof(char s[]);
    return (int) atof(s);
}

double atof (char s[]) {
    double pow, res;
    int i, flag, count, sign;

    for (i = 0; isspace(s[i]); i++); // Убираем пробелы слева

    // Записываю знак
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+') {
        ++i;
    }

    res = flag = count = 0;

    // Записываю все число и считаю кол-во цифр после точки
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
    // возвожу 10 в степень
    pow = 1;
    while (count-- > 0) {
        pow = pow * 10;
    }
    return sign * res / pow;
}

int myGetline (char s[]) {
    int c, i;
    for (i = 0; i < MAX - 1; i++) {
        if ((c = getchar()) != EOF && c != '\n') {
            s[i] = c;
        } else {
            break;
        }
    }
    if (c == '\n') {
        s[i++] = '\0'; 
    }
    
    return i;
}
