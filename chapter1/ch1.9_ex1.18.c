#include <stdio.h>
#define MAX 100
// Упр. 1.18
// Программа для удаления лишних пробельных символов в хвосте каждой поступающей строки 
// и удаления пустых строк

// поступают строки с входного потока
// удалить все лишние пробельные символы в конце строки
// пропустить пустую строку

int mygetline(char s[], int max);

int main(void) {
	char line[MAX];
	int len;

	while ((len = mygetline(line, MAX)) > 0) {
		// пропускаем нулевой символ
		--len;
		while (line[len] == ' ' || line[len] == '\t' || line[len] == '\n') {
			// пропускаем пробельные символы
			--len;
		}
		// если строка не пустая, добавляем нулевой символ и выводим
		if (len > 0) {
			line[len + 1] = '\0';
			printf("%s\n", line);
		}
	}

    return 0;
}

int mygetline(char s[], int max) {
	int c, i;

	for (i = 0; i < max - 1; i++) {
		if ((c = getchar()) != EOF && c != '\n') {
			s[i] = c;
		} else {
			break;
		}
	}
	if (c == '\n') {
		s[i++] = c;
	}

	s[i] = '\0';

	return i;
}
