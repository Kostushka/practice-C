#include <stdio.h>
#define IN 1
#define OUT 0

// Упр 1.12 (2)
// Программа для вывода входного потока по одному слову в строке (2)

int main (void) {

    int c;
    int state = OUT; // состояние вне/в слове - чтобы не печатать на каждый пробельный символ конец строки

    while ((c = getchar()) != EOF) {
        // если символ - не пустая строка и не tab
        if (c != ' ' && c != '\t') {
            // состояние в слове
            state = IN;
            // печатем символ
            putchar(c);
        // если символ - пустая строка или tab и состояние в слове
        } else if (state == IN) {
            // состояние вне слова
            state = OUT;
            // печатаем конец строки
            putchar('\n');
        }
       
    }
    // while ((c = getchar()) != EOF) {
    //     if (c != ' ' && c != '\t') {
    //         state = IN;
    //         putchar(c);
    //     } else if (state == OUT) {
            
    //     } else {
    //         state = OUT;
    //         putchar('\n');
    //     }
       
    // }

    return 0;
}