#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
#define NUM 1

// Упр. 4.10
// калькулятор с getline вместо getch и ungetch

double pop(void);
void push(double c);
int getop(char s[], char t[]);
int mygetline(char s[]);

int main(void) {
	char s[MAX];
	char t[MAX];
	double p;
	while (mygetline(s) > 0) {
		while (s)
		switch(getop(s, t)) {
			case NUM:
				push(atof(t));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				p = pop();
				push(pop() - p);
				break;	
			case '*':
				push(pop() * pop());
				break;
			case '/':
				p = pop();
				if (p != 0.0) {
					push(pop() / p);
				}
				break;
			case '\n':
				printf("%g\n", pop());
				break;
		}
	}
	return 0;
}

double stack[MAX];
int i = 0;

double pop(void) {
	if (i > 0) {
		return stack[--i];
	} else {
		printf("stack is empty\n");
		return 0;
	}
}

void push(double c) {
	if (i < MAX) {
		stack[i++] = c;
	} else {
		printf("stack is full\n");
	}
}

// "3 4 +\n"

int getop(char s[], char t[]) {
	int i, k, c;
	i = 0;

	while ((c = t[0] = s[i]) == ' ' || c == '\t') {
		++i;
	}
	t[1] = '\0';

	if (!isdigit(c) && c != '.') {
		return c;
	}
	k = 0;
	if (isdigit(c)) {
		while (isdigit(t[++k] = c = s[++i]));
	}

	if (c == '.') {
		while (isdigit(t[++k] = c = s[++i]));
	}

	t[k] = '\0';

	return NUM;
	
}

int mygetline(char s[]) {
	int c, i;
	for (i = 0; i < MAX - 1; i++) {
		if ((c = getchar()) != EOF && c != '\n') {
			s[i] = c;
		} else {
			break;
		}
	}
	
	if (c == '\n') {
		s[i++] = '\n';
	}
	
	s[i] = '\0';
	
	return i;
}
