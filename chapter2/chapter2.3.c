#include <stdio.h>
#include <string.h>
// 2.3 Константы

// Целочисленная константа: 123
// Вещетсвенная константа: 123.4
// Символьная константа: 'x'
// Константное выражение: #define MAXLINE 1000
// Строковая константа: "string" == 's''t''r''i''n''g''\0'
// Константы перечислимого типа: список целочисленных символических констант enum boolean {NO, YES};
//                                                                                         0    1
//                                                                  enum escapes {BELL = '\a', JAN = 1, FEB};

int myStrlen(char s[]);

int main (void) {

    enum escapes {BELL = '\a', TAB = '\t', JAN = 1, FEB, MAR};

    printf("%c %d %d %c %d\n", BELL, JAN, FEB, TAB, MAR);

    printf("%d\n", myStrlen("string"));
    printf("%d\n", strlen("string"));
    return 0;
}
// Считает количество символов в строковой константе - массиве символов до нулевого символа
int myStrlen (char s[]) {
    int i;
    for (i = 0; s[i] != '\0'; i++);
    return i;
}