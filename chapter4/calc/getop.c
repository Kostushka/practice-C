#include <stdio.h>
#include <ctype.h>
#include "calc.h"
#define NUM 1


int getop (char s []) {
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';

	if (!isdigit(c) && c != '.') {
		return c;
	}
	
	i = 0;
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch()));
	}

	if (c == '.') {
		while (isdigit(s[++i] = c = getch()));
	}

	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUM;
}
