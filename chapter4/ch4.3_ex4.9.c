#include <stdio.h>
#define MAX 100
// Упр. 4.9 
// корректно обрабатывать EOF ??? 
// EOF не помещается в буфер, он используется для выхода из цикла, принимающего символы с потока ввода

int getch(void);
void ungetch(int c);

int main(void) {
	return 0;
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
