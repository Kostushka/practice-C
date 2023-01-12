#include <stdio.h>

// Упр. 3.2
// Функция escape(s, t) -> 
// копирует строку t в строку s
// конвертирует символ конца строки -> \n
// конвертирует символ табуляции -> \t

void escape(char s[], char t[]);

int main (void) {
    char s[20];
    char t[] = "H   e   l   l   o!";

    escape(s, t);
    printf("%s %s\n", s, t);

    return 0;
}

void escape (char s[], char t[]) {

    int i;

    for (i = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\n':
                s[i] = '\\';
                s[++i] = 'n';
                break;
            case '\t':
                // не попадает
                s[i] = '\\';
                s[++i] = 't';
                break;
            default: 
                s[i] = t[i];
                break;
        }
    }
    s[i] = '\0';
}