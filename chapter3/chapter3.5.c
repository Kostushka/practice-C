#include <stdio.h>
#include <ctype.h>
#include <string.h>

// 3.5 Циклы while и for

/*
for (выраж1; выраж2; выраж3) {
    оператор;
}

выраж1;
while (выраж2) {
    оператор;
    выраж3;
}
*/

int atoi (char s[]);

void reverse (char s[]);

void shellsort(char s[], int n);

int main (void) {

    char s[] = "    -123";

    char str[] = "hello";
    reverse(str);
    printf("%s\n", str);

    printf("%d\n", atoi(s));

	char el[] = {23, 45, 2, 9, 44, 1, 89, 54, 3, -12, 8, 0};
	int len = 12;
    shellsort(el, len);
	for (int n = 0; n < len; n++) {
		printf("%d\t", el[n]);
	}	

    return 0;
}

int atoi (char s[]) {

   int i, sign, n;

    // пропуск пробельных символов в начале строки
    for (i = 0; isspace(s[i]); i++);    
    // for (i = 0; s[i] == ' '; i++);

    // записываем знак
    sign = (s[i] == '-') ? -1 : 1;

    // пропуск знака
    if (s[i] == '+' || s[i] == '-') {
        ++i;
    }

    // преобразуем строку в число
    for (n = 0; isdigit(s[i]); i++) {
        n = n * 10 + (s[i] - '0');
    }
    // for (n = 0; s[i] >= '0' && s[i] <= '9'; i++) {
    //     n = n * 10 + (s[i] - '0');
    // }

    return sign * n;
}

// Операция запятая

void reverse (char s[]) {
    int i, j, c, countLength;

    // countLength = 0;

    // for (i = 0; s[i] != '\0'; ++i) {
    //     ++countLength;
    // }

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    // for (i = 0, j = countLength - 1; i < j; i++, j--) {
    //     c = s[i];
    //     s[i] = s[j];
    //     s[j] = c;
    // }
}

// сортировка массива целых чисел
void shellsort(char s[], int n) {
	int gap, i, j;
	// меняет расстояние между сравниваемыми элементами
	for (gap = n / 2; gap > 0; gap /= 2) {
		// следующий шаг - перебор элементов
		for (i = gap; i < n; i++) {
			// 										0         3
			// замена элементов при необходимости [25 ..gap.. 1]
			for (j = i - gap; j >= 0 && s[j] > s[j+gap]; j -= gap) {
				int temp = s[j];
				s[j] = s[j + gap];
				s[j + gap] = temp;
			}
		}
	}
}
