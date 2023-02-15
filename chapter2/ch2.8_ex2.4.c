#include <stdio.h>

// Упр 2.4 
// Удаляет из строки s1 все символы, которые есть в s2
// "hello" "how" 
// h == h -> пропускаем
// e != h e != o e != w -> записываем
// ... 
// o != h o == o -> пропускаем
// hello\0 ->  e ello\0 -> el llo\0 -> ell lo\0 -> ell\0
void squeeze (char s1[], char s2[]);

int main (void) {

    char str1[] = "hello how are you";
    char str2[] = "eoayu";

    squeeze(str1, str2);

    printf("%s\n", str1);

    return 0;
}

void squeeze (char s1[], char s2[]) {
    int i, j, k, state;

    k = 0;
    // берем первый символ первой строки
    for (i = 0; s1[i] != '\0'; ++i) {

        state = 0;
        // проверяем на соответствие с каждым символом второй строки
        for (j = 0; s2[j] != '\0'; ++j) {
            // выходим из цикла, если обнаружим соответствие, 
            // переходим к следующему символу первой строки
            if (s1[i] == s2[j]) {
                state = 1;
                break;
            }
        }
        // если соответствия нет, перезаписываем символ
        if (!state) {
            s1[k++] = s1[i];
        }
    }

    // конец строки
    s1[k] = '\0';
}
