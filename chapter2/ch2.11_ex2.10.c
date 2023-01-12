#include <stdio.h>

// Упр. 2.10
// tolowerCase с тернарным оператором
char tolowerCase (char s);

int main (void) {

    int c;

    while ((c = getchar()) != EOF) {
        printf("%c", tolowerCase(c));
    }

    return 0;
}

char tolowerCase (char s) {
    return s >= 'A' && s <= 'Z' ? s + ('a' - 'A') : s;
}