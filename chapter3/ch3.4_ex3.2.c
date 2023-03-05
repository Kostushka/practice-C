#include <stdio.h>
#define LIM 100
// Упр. 3.2
// Функция escape(s, t) -> 
// копирует строку t в строку s
// конвертирует символ конца строки -> \n
// конвертирует символ табуляции -> \t

void escape(char s[], char t[]);

int main (void) {
    char s[LIM];
    char t[] = "H e l l o!";
    printf("%s", t);
    escape(s, t);
    printf("%s", s);

    return 0;
}

void escape (char s[], char t[]) {

	int len, i;

	for (len = 0; t[len] != '\0'; len++);

    for (i = 0; i <= len; ++i) {
        switch (t[i]) {
            case '\0':
                s[i] = '\n';
                break;
            case ' ':
                s[i] = '\t';
                break;
            default: 
                s[i] = t[i];
                break;
        }
    }
    s[i] = '\0';
}
