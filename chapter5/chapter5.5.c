#include <stdio.h>
#include <string.h>

// 5.5 Символьные указатели и функции
// char amessage[] = "hello, world"; // массив - всегда указывает на один и тот же участок памяти
// char *pmessage = "hello, world"; // указатель - можно изменить, чтобы указывал на другое место

// копирует строку t в s
void strcpy1 (char s[], char t[]);
void strcpy2 (char *s, char *t);

// сравнивает строки s и t
// возвращает s[i] < t[i] => <0; s[i] == t[i] => 0; s[i] > t[i] => >0
int strcmp1 (char s[], char t[]);
int strcmp2 (char *s, char *t);

int main (void) {

	char s[] = "hello";
	char t[] = "good";
	printf("%d\n", strcmp1(s, t));
	printf("%d\n", strcmp2(s, t));
	printf("%p\n", strcpy(s, t)); // strcpy из библиотеки возвращает указатель на строку, в котор. выполняется копирование
	printf("%s %s\n", s, t);
	strcpy2(s, t);
	printf("%s %s\n", s, t);

	return 0;
}

void strcpy1 (char s[], char t[]) {
	int i;
	i = 0;
	while ((s[i] = t[i]) != '\0') {
		++i;
	}
}

void strcpy2 (char *s, char *t) {
	while ((*s = *t) != '\0') {
		++s;
		++t;
	}
}

// void strcpy2 (char *s, char *t) {
	// while ((*s++ = *t++) != '\0');
// }

// void strcpy2 (char *s, char *t) {
	// while (*s++ = *t++);
// }

int strcmp1 (char s[], char t[]) {
	int i;
	// пока символы соответсвуют
	for (i = 0; s[i] == t[i]; i++) {
		if (s[i] == '\0') {
			// строки идентичны
			return 0;
		}
	}
	return s[i] - t[i];
}

int strcmp2 (char *s, char *t) {
	// пока символы соответсвуют
	while (*s == *t) {
		if (*s == '\0') {
			// строки идентичны
			return 0;
		}
		++s;
		++t;
	}
	return *s - *t;
}
