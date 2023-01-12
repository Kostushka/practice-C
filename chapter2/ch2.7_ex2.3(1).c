#include <stdio.h>

// Упр. 2.3 (1)
// Программа, которая преобразует строку 16-чных цифр в число
int getNum (char c);
int htoi (char s[]);

int main (void) {

    char s[] = "0xfffF";

    printf("%0X: %d\n", htoi(s), htoi(s));

    return 0;
}


int htoi (char s[]) {

    int i, start, c, res;

    start = res = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        start = 2;
    }

    for (i = start; (c = getNum(s[i])) != -1; ++i) {
        res = res * 16 + c;
    }

    return res;
}

int getNum (char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }

    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }

    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }

    return -1;
}