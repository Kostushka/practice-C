#include <stdio.h>
#define MAXLINE 1000

// 1.9 Массив символов - наиболее распространенный тип массивов
// Программа, которая считывает набор строк и выводит самую длинную строку

int getcurrline (char line[], int maxline);
void copy (char maxline[], char line[]);

int main (void) {

    int len; // длина текущей строки
    int max; // максимальная длина строки
    char line[MAXLINE]; // массив для 1000 байт == 1000 символов текущей строки
    char maxline[MAXLINE]; // массив символов максимальной по длине строки

    max = 0;

    while ((len = getcurrline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(maxline, line);
        }
        if (max > 0) {
        printf("%s %d %d\n", maxline, len, max);
        }
    }

    // if (max > 0) {
    //     printf("%s %d %d\n", maxline, len, max);
    // }

    return 0;
}

// записать текущую строку в массив символов текущей строки и вернуть длину текущей строки
int getcurrline (char line[], int maxline) {

    int c, i;

    // записываем символы, пока лимит символов в массиве не превышен, пока не конец файла и не конец строки
    // инкрементируем счетчик длины строки i на записываемые в массив символы
    for (i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }
    // если конец строки, записываем символ конца строки в массив строки
    // инкрементируем счетчик длины строки i на символ конца строки
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    // записываем в массив нулевой символ - конец строки символов по стандарту
    line[i] = '\0';
    // возвращаем длину строки
    return i;

}

// копирует строку line в maxline
void copy (char maxline[], char line[]) {

    int i;

    i = 0;
    // копируем символы из line в массив maxline, пока это не нулевой символ
    while ((maxline[i] = line[i]) != '\0') {
        ++i;
    }
}