#include <stdio.h>
#define IN 1
#define OUT 0

// Упр 1.13
// Программа вывода гистограммы длин слов во входном потоке

int main (void) {

    int c, i;
    int state = OUT;
    int count = 0; // счетчик символов в слове

    while ((c = getchar()) != EOF) {
        // если не пробельный символ
        if (c != ' ' && c != '\t' && c != '\n') {
            // состояние - в слове
            state = IN;
            // инкремент счетчика
            ++count;
        // если пробельный символ и состояние - в слове
        } else if (state == IN) {
            // состояние - вне слова
            state = OUT;

            // гистограмма
            printf("|");
            for (i = 1; i <= count; i++) {
                printf("_");
            }
            putchar('\n');
            printf("|\n");           

            // обнуляем счетчик
            count = 0;
        } 
    }

    return 0;
}