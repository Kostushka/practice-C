#include <stdio.h>
#define MAX 100

// Упр.4.7 
// ungets(s) - возвращает в поток строку

void ungets(char s[]);
void ungetch(char c);

int main(void) {
	return 0;
}

// символы из потока
char buf[MAX];
int b = 0;

void ungetch(char c) {
	if (b < MAX) {
		buf[b++] = c;
	}
}

void ungets(char s[]) {
	int i = 0;
	while (s[i] != '\0' && b < MAX) {
		ungetch(s[i]);
		++i;
	}
}
