#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
// Упр. 7.5
// калькулятор через scanf/sscanf

int getop(char *s);

int main(void) {

	int x;
	char line[2];
	char op;
	int res;
	
	res = 0;
	
	while (scanf("%d", &x) == 1 && getop(line) != EOF && sscanf(line, "%c", &op) == 1) {
		switch(op) {
			case '+':
				res += x;
				break;
			case '-':
				res -= x;
				break;
			case '*':
				res *= x;
				break;
			case '/':
				if (x != 0) {
					res /= x;
				} else {
					printf("invalid value\n");
				}
				break;
		}
		
		printf("Итого: %d\n", res);	
		
	}


	
	return 0;
}

int getop(char *s) {
	int c;
	while (isspace(c = getchar()));
	if (c != EOF) {
		*s++ = c;
	}
	*s = '\0';

	return c;
}
