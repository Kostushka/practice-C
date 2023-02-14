#include <stdio.h>
#define MAX 11

// Упр. 1.22 Сворачивание длинных строк в две или более строки после последнего не пустого символа перед n столбцом (+ удаление пробельных символов перед n)

// blablabla

// blabla
// bla

int mygetline(char s[], int max);

int main(void) {

	char s[MAX];
	int len;

	while ((len = mygetline(s, MAX)) > 0) {
		
		--len;
		
		// пропускаем пробельные символы
		while (s[len] == ' ' || s[len] == '\t') {
			--len;
		}
		if (len >= 0) {
			s[++len] = '\0';

			if (s[--len] == '\n') {
				printf("%s", s);
			} else {
				printf("%s\n", s);
			}
		}

	}
	
	return 0;
}

int mygetline(char s[], int max) {
	int i, c;

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
