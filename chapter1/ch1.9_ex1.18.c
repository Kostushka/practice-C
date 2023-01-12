#include <stdio.h>
#define IN 1
#define OUT 0
// Упр. 1.18
// Программа для удаления лишних пробельных символов в хвосте каждой поступающей строки 
// и удаления пустых строк

void deleteSpace (char s[]);

int main (void) {

    int c, i;
    char s[1000];

    for (i = 0; i < 1000 - 2 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = '\n';
        ++i;
    }
    s[i] = '\0';

    // deleteSpace(s);
    // printf("%s", s);
    char g[] = "Hello      ";
    deleteSpace(g);
    printf("%s", g);

    return 0;
}

void deleteSpace (char s[]) {

    int i, k, state;

    i = k = 0;
    state = OUT;

    if (s[0] == '\n') {
        s[0] = '\0';
    }

    while (s[i] != '\0') {
        if (s[i] != ' ') {
            state = IN;
            s[k++] = s[i];
        } else if (state == IN) {
            state = OUT;
            s[k++] = s[i];
        }
        ++i;
    }
    s[i] = '\0';

}