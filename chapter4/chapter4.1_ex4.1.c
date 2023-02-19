#include <stdio.h>
#define LIM 1000

// 4.1 Основы создания функций
// Упр. 4.1 Функция strrindex(s, t) - индекс самого правого вхождения строки t в s

// Если функции в разных файлах

// компилируем все вместе: 
// cc main.c getline.c strindex.c

// получаем объектный код: main.o getline.o strindex.o

// перекомпилируем отдельный файл при необходимости и компонуем с другими: 
// cc main.c getline.o strindex.o

// Получить строку с входного потока
int myGetline (char s[]);

// Проверить наличие образца в строке
// Возвращает индекс начала строки pattern в s
// hello\0 llo\0
int strindex (char s[], char pattern[]);

// индекс самого правого вхождения строки t в s
int strrindex (char s[], char t[]);

// поиск всех строк с заданным образцом
int main (void) {

    int found;
    char s[LIM];
    char pattern[] = "ould";
    found = 0;

    // Пока есть строка
    while (myGetline(s) > 0) {
        printf("left: %d\n", strindex(s, pattern));        
        printf("right: %d\n", strrindex(s, pattern));        
        // если не -1
        if (strindex(s, pattern) >= 0) {
            printf("%s", s);
            ++found;
        }
    }
    return found;
}

int myGetline (char s[]) {

    int c, i;

    for (i = 0; i < LIM - 1; i++) {
        if ((c = getchar()) != EOF && c != '\n') {
            s[i] = c;       
        } else {
            break;
        }
    }

    if (c == '\n') {
        s[i++] = '\n';
    }

    s[i] = '\0';

    return i;

}

int strindex (char s[], char pattern[]) {
    int i, j, k;
    // Пока не конец строки
    for (i = 0; s[i] != '\0'; i++) {
        // Перебор на соответствие с выбранного символа
        for (j = i, k = 0; pattern[k] != '\0' && s[j] == pattern[k]; j++, k++);
        // Если дошли до конца образца, вернуть индекс начала соответствия в строке
        if (k > 0 && pattern[k] == '\0') {
            return i;
        }
    }
    // соответствие не найдено
    return -1;
}

// could could
// right: 7

int strrindex (char s[], char t[]) {
    int i, j, k, res;
    res = 0;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        if (k > 0 && t[k] == '\0') {
            res = i;
        }
    }
    if (res) {
    	return res;
    }
    return -1;
}

// could
// right: 4

// int strrindex (char s[], char t[]) {
    // int i, j, k;
    // for (i = 0; s[i] != '\0'; i++) {
        // for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++);
        // if (k > 0 && t[k] == '\0') {
            // return j - 1;
        // }
    // }
    // return -1;
// }
