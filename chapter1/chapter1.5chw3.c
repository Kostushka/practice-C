#include <stdio.h>

// Программа для копирования входного потока в выходной с заменой символов табуляции - на \t, символов Backspace - на \b, символов обратных косых черт на \\

int main (void) {

    int c;

    while ((c = getchar()) != EOF) {

        switch (c) {
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            case '\\':
                printf("\\\\");
                break;
            default: 
                putchar(c);
        }

        // if (c == '\t') {
        //     printf("\\t");
        // } else if (c == '\b') {
        //     printf("\\b");
        // } else if (c == '\\') {
        //     printf("\\\\");
        // } else {
        //     putchar(c);
        // }
    }
    
    return 0;
}