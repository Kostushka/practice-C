#include <stdio.h>
#include <ctype.h>
#define MAX 10

// Упр. 5.1 
// getint, которая возвращает знак в поток

int getint(int *p);
int getch(void);
void ungetch(int c);

int main(void) {
	int num[MAX], n;
	for (n = 0; n < MAX && getint(&num[n]) != EOF; n++) {
		printf("%d %d\n", n, num[n]);
	}
	return 0;
}

int getint(int *p) {
	int c, sign;
	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}

	if (c == '+' || c == '-') {
		ungetch(c); // ???
	}

	sign = (c == '-') ? -1 : 1;

	if (c == '-' || c == '+') {
		c = getch();
	}

	for (*p = 0; isdigit(c); c = getch()) {
		*p = 10 * *p + (c - '0');
	}

	*p *= sign;

	if (c != EOF) {
		ungetch(c);
	}

	return c;
	
}

char buf[MAX];
int i = 0;

int getch(void) {
	return i > 0 ? buf[--i] : getchar();
}

void ungetch(int c) {
	if (i < MAX) {
		buf[i++] = c;
	}
}
