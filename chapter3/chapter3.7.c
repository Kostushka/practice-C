#include <stdio.h>

// 3.7 Операторы break, continue

// Функция убирает пробельные символы в конце строки
void trim (char s[]);

int positive (int n);

int main (void) {

    char s[] = "HEllo               ";

    printf("%s!\n", s);

    trim(s);

    printf("%s!\n", s);

    return 0;
}

void trim (char s[]) {

    int length;

    for (length = 0; s[length] != '\0'; length++);

    while (--length >= 0) {
        if (s[length] != ' ' && s[length] != '\t' && s[length] != '\n') {
            break;
        }
    }

    s[++length] = '\0';

}

int positive (int n) {
    int i;

    for (i = -5; i < n; i++) {
        if (i < 0) {
            continue;
        } else {
            return i;
        }
    }
}