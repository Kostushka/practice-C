#include <stdio.h>
// #define MAX 1

// Упр. 4.8 
// в поток ввода никогда не будет возвращаться больше одного символа ???

int getch(void);
void ungetch(int c);

int main(void) {
	return 0;
}

char buf[] = {0};
int i = 0;

int getch(void) {
	return (buf[i] != 0) ? buf[i] : getchar();
}

void ungetch(int c) {
	buf[i] = c;
}
