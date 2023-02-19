#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
#define NUM 1

// Упр. 4.3
// добавить в калькулятор операцию взятия остатка и работу с отрицательными числами

void push(double c);
double pop(void);
int getch(void);
void ungetch(int c);
int getop(char s[]);

int main(void) {
	double p;
	int c;
	char s[MAX];
	while ((c = getop(s)) != EOF) {
		switch (c) {
			case NUM:
				push(atof(s));
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
			case '%':
				p = pop();
				push((int) pop() % (int) p);
				break;
			case '\n':
				printf("%g\n", pop());
				break;
			default:
				printf("some: error\n");
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

int getop(char s[]) {
	int c, i, n;
	
	while((s[0] = c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	
	if (!isdigit(c) && c != '.') {
		// if (c == '-' || c == '+') {
			// if (isdigit(n = getch())) {
				// ungetch(n);
			// } else {
				// return c;
			// }
		// }
		return c;
	}
	
	i = 0;
	// if (isdigit(c) || c == '+' || c == '-') {
		while(isdigit(s[++i] = c = getch()));
	// }
	if (c == '.') {
		while(isdigit(s[++i] = c = getch()));
	}
	s[i] = '\0';
	if (c != EOF) {
		ungetch(c);
	}
	return NUM;
}

char buf[MAX];
int b = 0;

int getch(void) {
	return b > 0 ? buf[--b] : getchar();
}

void ungetch(int c) {
	if (b < MAX) {
		buf[b++] = c;
	} else {
		printf("error\n");
	}
}
