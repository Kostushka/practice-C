#include <stdio.h>

// Инкремент и декремент
// префиксный - приращение единицы до того, как используется
// постфиксный - после того, как используется 

// Удаляет все символы с в строке s
// "hello" -> h != l e != l l == l l == l o != l
void squeeze (char s[], int c);
// Конкатенация строк
// "hello" -> 0 1 2 3 4 \0 -> 5 j 6 t 7 \0
void myStrcat (char s1[], char s2[]);

int main (void) {

    char str[10] = "hello";
    char str2[] = "bye";
    int x, y, n;
    n = 5;
    x = n++; // x = 5 n = 6
    y = ++n; // n = 7 y = 7
    printf("%d %d %d\n", x, y, n);

    squeeze(str, 'l');
    printf("%s\n", str);

    myStrcat(str, str2);
    printf("%s %s\n", str, str2);

    return 0;
}

void squeeze (char s[], int c) {
    int i, j;

    i = j = 0;

    while (s[i] != '\0') {
        if (s[i] != c) {
            // перезаписываем символ строки s, если он не равен c
            s[j++] = s[i];
            // ++j;
        }
        ++i;
    }
    // обозначаем конец строки
    s[j] = '\0';
}

void myStrcat (char s1[], char s2[]) {

    int i, j;

    i = j = 0;
    // находим индекс последнего символа + 1
    while (s1[i] != '\0') {
        ++i;
    }
    // последовательно записываем символы второй строки
    while ((s1[i++] = s2[j++]) != '\0');
}