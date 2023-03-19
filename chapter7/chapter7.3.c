#include <stdio.h>
#include <stdarg.h>

// 7.3 Списки аргументов переменной длины
// тип va_list - ссылается по очереди на каждый аргумент
// макрос va_start - инициализирует переменную, чтобы она указывала на первый безымянный аргумент
// va_arg - возвращает один аргумент и передвигает указатель на следующий
// va_end - завершающие операции

void minprintf (char *fmt, ...); // аргументы: указатель на тип char, аргументы переменной длины

int main (void) {
	minprintf("Hello %d, %s, %f, %c %o %x!\n", 23, "lala", 23.6, 't', 10, 10);
	return 0;
}

void minprintf (char *fmt, ...) {
	va_list ap;
	char *p, *sval, cval;
	int ival, oval, xval;
	double dval;

	va_start(ap, fmt);
	for (p = fmt; *p; p++) {
		if (*p != '%') {
			putchar(*p);
			continue;
		}
		switch (*++p) {
			case 'd':
				ival = va_arg(ap, int);
				printf("%d", ival);
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%f", dval);
				break;
			case 's':
				for (sval = va_arg(ap, char *); *sval; sval++) {
					putchar(*sval);
				}
				break;
			case 'c':
				cval = va_arg(ap, int);
				putchar(cval);
				break;
			case 'o':
				oval = va_arg(ap, int);
				printf("%o", oval);
				break;
			case 'x':
			case 'X':
				xval = va_arg(ap, int);
				printf("%x", xval);
				break;
			default:
				putchar(*sval);
				break;
		} 
	}
	va_end(ap);
}
