#include <stdio.h>
#define MAX 100

// Упр. 1.19
// hello
// oellh
// olleh

void reverse(char s[]);
int mygetline(char s[], int max);

int main(void) {
	int len;
	char s[MAX];
	
	// получаем строку
	while ((len = mygetline(s, MAX)) > 0) {
		// удаляем символ переноса строки
		if (s[--len] == '\n') {
			s[len] = '\0';
		}
		// переворачиваем и выводим
		reverse(s);
		printf("%s\n", s);
	}
	return 0;
}

void reverse(char s[]) {
	int len, start, end;

	for (len = 0; s[len] != '\0'; len++);

	for (start = 0, end = len - 1; start < end; start++, end--) {
		int c;
		c = s[start];
		s[start] = s[end];
		s[end] = c;
	}
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
