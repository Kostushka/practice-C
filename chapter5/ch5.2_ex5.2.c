#include <stdio.h>
#include <ctype.h>
#define MAX 10

// Упр. 5.2
// getfloat - для получения вещественных чисел из входного потока

int getfloat (double *);
int getch (void);
void ungetch (int c);

int main (void) {

	double num[MAX];
	int i;

	for (i = 0; i < MAX && getfloat(&num[i]) != EOF; i++) {
		printf("%d: %g\n", i, num[i]);
	}

	return 0;
}

int getfloat (double *n) {
	int c, sign;
	double pow;

	// пропускаем пробельные символы
	while (isspace(c = getch()));

	// записываем не число и выходим
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}

	// записываем знак, запрашиваем следующий символ
	sign = c == '-' ? -1 : 1;
	if (c == '-' || c == '+') {
		c = getch();
	}

	// записываем число, пока цифровые символы
	for (*n = 0; isdigit(c); c = getch()) {
		*n = *n * 10 + (c - '0');
	}

	// если точка, продолжаем записывать число, пока после точки идут цифровые символы
	// записываем десятки
	pow = 1;
	if (c == '.') {
		while (isdigit(c = getch())) {
			*n = *n * 10 + (c - '0');
			pow = pow * 10;
		}
	}

	// записываем окончательное вещественное число
	*n = sign * *n / pow;

	// нецифровой символ запоминаем
	if (c != EOF) {
		ungetch(c);
	}
	// возвращаем на случай, если EOF
	return c;	
}



char buf[MAX];
int b = 0;

int getch (void) {
	return b > 0 ? buf[--b] : getchar();
}

void ungetch (int c) {
	if (b < MAX) {
		buf[b++] = c;
	}
}
