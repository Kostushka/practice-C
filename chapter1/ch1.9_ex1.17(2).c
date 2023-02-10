#include <stdio.h>
#define MAX 83
// Вывод строк длиной более 80 символов

int mygetline(char s[], int max);

int main(void) {

	int len, c;
	char curline[MAX];

	while ((len = mygetline(curline, MAX)) > 0) {
		if (len == MAX - 1) {
			printf("%s", curline);
			while ((c = getchar()) != EOF) {
				if (c == '\n') {
					putchar(c);
					break;
				}
				putchar(c);
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
