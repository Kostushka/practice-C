#include <stdio.h>
#include <ctype.h>

// Упр.3.3
// Функция expand(s1, s2) -> 
// разворачивает a-z -> abc...xyz
// разворачивает a-b-c -> abc
// разворачивает a-z0-9 -> abc...xyz012...789
// разворачивает -a-z -> -abc...xyz
// учитывать любой регистр
// - в начале и в конце == не символ развертывания

void expand (char s1[], char s2[]);

int main (void) {

    return 0;
}

void expand (char s1[], char s2[]) {

    int i, j, length;

    i = j = 0; 

    // пропуск - в начале и в конце строки
    for (length = 0; s1[length] != '\0'; length++);
    if (s1[i] == '-' || s1[length - 1] == '-') {
        ++i;
        --length;
    }

    while(s1[i] <= length - 1) {
        if (s1[i] != '-') {
            s2[j] = s1[i];
        } else {
            int a = --i;
            ++i;
            int b = ++i;
            --i;

        }
    }

   

}