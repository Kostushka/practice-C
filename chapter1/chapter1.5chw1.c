#include <stdio.h>

// Программа для подсчета символов пробела, табуляции, конца строки

int main (void) {

    int c, t, n; // переменные для подсчета символов пробела, табуляции, конца строки    
    int v;

    c = t = n = 0;

    while ((v = getchar()) != EOF) {
        switch (v) {
            case ' ':
                ++c;
                break;
            case '\t':
                ++t;
                break;
            case '\n':
                ++n;
        }
    }
    // while ((v = getchar()) != EOF) {
    //     if (v == ' ') {
    //         ++c;
    //     } else if (v == '\t') {
    //         ++t;
    //     } else if (v == '\n') {
    //         ++n;
    //     }
    // }
    printf("c: %d t: %d n: %d", c, t, n);

    return 0;
}