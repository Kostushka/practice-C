#include <stdio.h>
#include "calc.h"
#define MAX 100

char buf[MAX];
int bufi = 0;

int getch (void) {
	return (bufi > 0) ? buf[--bufi] : getchar(); 
}

void ungetch (int c) {
	if (bufi < MAX) {
		buf[bufi++] = c;
	} else {
		printf("buf full");
	}
}
