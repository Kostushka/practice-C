#include <stdio.h>

// Упр. 2.5
// Функция any (s1, s2) => номер первого символа s1, соответсвующий любому символу s2 иначе -1

int any (char s1[], char s2[]);

int main (void) {

    char str1[] = "kukuruza";
    char str2[] = "nmrau";

    printf("%c\n", any(str1, str2));

    return 0;
}

int any (char s1[], char s2[]) {
    int i, j;

    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j]) {
                return i;
            }
        }
    }

    return -1;
}
