#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Упр 7.1 
// Перевод входных данных из верхнего регистра в нижний - в зависимости от регистра букв имени программы при запуске
// "lower" или "LOWER" - проверить первую букву имени программы при запуске

int tocapse (int c);

int main (int argc, char *argv[]) {

	int c;

	// находим первую букву имени программы
	while (!isalpha(*argv[0])) {
		argv[0]++;
	}

	// если первая буква имени программы - маленькая, то входные данные выводим в нижнем регистре
	if (*argv[0] - tolower(*argv[0]) == 0) {
		while ((c = getchar()) != EOF) {
			putchar(tolower(c));
		}
	// иначе выводим в верхнем регистре
	} else {
		while ((c = getchar()) != EOF) {
			putchar(tocapse(c));
		}
	}

	// printf("%c\n", *argv[0]);
	
	return 0;
}

int tocapse (int c) {
	if (c > 'a' && c < 'z') {
		return c - ('a' - 'A');
	}

	return c;
}
