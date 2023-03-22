#include <stdio.h>
#include <stdarg.h>

// Упр. 7.4
// minscanf - миниреализация scanf

void minscanf(char *c, ...);

int main(void) {
	int a;
	char s[10];
	minscanf("%d %s", &a, s);
	printf("%d %s\n", a, s);
	return 0;
}

void minscanf(char *c, ...) {
	va_list ap; // указатель на безымянные арг
	char *p;
	int *ival;
	char *sval;

	va_start(ap, c); // указатель на 1ый безымянный арг
	for (p = c; *p; p++) {
		if (*p != '%') {
			continue;
		}
		switch(*++p) {
			case 'd':
				ival = va_arg(ap, int *);
				scanf("%d", ival);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++) {
					scanf("%s", sval);
				}
				break;
		}
	}
	va_end(ap);
}
