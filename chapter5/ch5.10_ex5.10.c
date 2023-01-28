#include <stdio.h>
#include <ctype.h>
#define MAX 100

// Упр. 5.10
// Программа expr - вычисляет выражения в обратной польской записи из командной строки
// 2 3 4 + * => 3 + 4 => 2 * 7 => 14

int atoi (char *s);
void push (int a);
int pop (void);

int main (int argc, char *argv[]) {
	int num, op;
	++argv;
	while (--argc > 0) {
		printf("arg: %s\n", *argv);
		switch (*argv[0]) {
			case '+': 
				push(pop() + pop());
				break;
			case '-': 
				op = pop();
				push(pop() - op);
				break;
			case '*': 
				push(pop() * pop());
				break;
			case '/': 
				op = pop();
				if (op != 0) {
					push(pop() / op);	
				} 
				break;
			case ' ': 
				printf(" ");
				break;
			case '\n':
				printf("%d\n", pop());
				break;
			default:
				break;
			
		}
		if (isdigit(num = atoi(*argv))) {
			push(num);
		}
		++argv;

	}
		
	
	return 0;
}

int atoi (char *s) {
	int n, i; 
	n = 0;
	for (i = 0; s[i] != '\0'; i++ ) {
		n = n * 10 + (s[i] - '0');
	}
	printf("%d\n", n);
	return n;
}

char stack[MAX];
int p = 0;

void push (int a) {
	if (p < MAX) {
		stack[p++] = a;
	} else {
		printf("stack full\n");
	}
}

int pop (void) {
	if (p > 0) {
		return stack[--p];
	} else {
		printf("stack empty\n");
		return 0;
	}
}
