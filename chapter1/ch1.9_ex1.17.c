#include <stdio.h>
#define LIMIT 11

// Упр. 1.17
// Программа вывода всех строк входного потока с длиной более 80 символов

int main (void) {

    int i, c, count;
    char line[LIMIT]; // максимальная длина строки 80 + \0

    count = 0;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            line[count] = c;
            ++count;
            if (count == LIMIT - 1) {
                line[count] = '\0';
                printf("%s", line);
                while ((c = getchar()) != '\n' && c != EOF) {
                    putchar(c);
                }
                printf("\n");
                for (i = 0; i < 10; i++) {
                    line[i] = 0;
                }
                count = 0;
            }      
        } else {
            for (i = 0; i < 10; i++) {
                line[i] = 0;
            }
            count = 0;
        }
    }

    return 0;
}


// int main (void) {

//     int c, i, count;
//     char line[10];
//     count = 0;

//     for (i = 0; i < 10; i++) {
//         c = getchar();
//         if (c != EOF && c != '\n') {
//             line[i] = c;
//             ++count;
//         }
//     }
    
//     if (count == 10 && (c = getchar()) != EOF && (c = getchar()) != '\n') {
//         printf("%s%c\n", line, c);
//         i = 0;
//     }


//     return 0;
// }