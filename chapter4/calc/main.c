#include <stdio.h>
#include <stdlib.h>
#include "calc.h"
#define NUM 1
#define MAX 100

// 4.5 Заголовочные файлы calc.h - хранит объявления и определения функций для совместного использования

int main (void) {

	int typeChar;
	char s[MAX];
	double op2;

	while ((typeChar = getop(s)) != EOF) {
		switch (typeChar) {
			case NUM: 
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '*':
				push(pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0) {
					push(pop() / op2);
				} else {
					printf("invalid operation\n");
				}
				break;
			case '\n':
				printf("result: %g\n", pop());
				break;
			default: 
				printf("not valid value: %s", s);
				break;
		}
	}
	
	return 0;
}
