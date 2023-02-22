#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX 100
#define NUM 1

// Упр. 4.11 Изменить функцию getop, чтобы ей не надо было использовать ungetch
// статическая переменная

int getop(char s[]);
double pop(void);
void push(double f);

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

// 4 7 + 6 +

int getop(char s[]) {
	int c, i;
	// статическая переменная
	static int uc;

	// если есть нечисловой символ и он не пробельный, записываем его и зануляем переменную с ним
	if (uc && uc != ' ' && uc != '\t') {
		s[0] = c = uc;
		uc = 0;
	} else {
		while ((s[0] = c = getchar()) == ' ' || c == '\t');
	}
	
	s[1] = '\0';

	if (!isdigit(c) && c != '.') {
		return c;
	}
	
	i = 0;
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getchar()));
	}

	if (c == '.') {
		while (isdigit(s[++i] = c = getchar()));
	}

	s[i] = '\0';

	if (c != EOF) {
		// записываем символ после числа
		uc = c;
	}

	return NUM;
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

