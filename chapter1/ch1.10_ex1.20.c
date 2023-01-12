#include <stdio.h>
#define LIM 4

// Упр. 1.20
// Программа заменяет символы tab во входном потоке на соответсвующее кол-во пробелов
// пусть tab == 4 знакоместа 
// 4 пробела, если символов подряд >= 4
// 3 пробела, если символов подряд 1
// 2 пробела, если символов подряд 2
// 1 пробела, если символов подряд 3

int main (void) {

    int c, i;
    char s[LIM];  

    i = 0;  

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            switch (i) {
                case 0:
                    putchar(' ');
                    putchar(' ');
                    putchar(' ');
                    putchar(' ');                    
                    break;
                case 1:
                    putchar(' '); 
                    putchar(' '); 
                    putchar(' '); 
                    break;
                case 2:
                    putchar(' '); 
                    putchar(' ');
                    break;
                case 3:
                    putchar(' ');
                    break;
                case 4: 
                    putchar(' ');
                    putchar(' ');
                    putchar(' ');
                    putchar(' '); 
                    break;
                default:
                    putchar(' ');
                    putchar(' ');
                    putchar(' ');
                    putchar(' '); 
            }
            i = 0;
        } else if (c != '\n') {
            if (i < LIM) {
                s[i++] = c;
            } else {
                i = 0;
            }
            putchar(c);
        } else {
            putchar(c);
        }
    }

    return 0;
}