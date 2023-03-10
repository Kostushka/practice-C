#include <stdio.h>
#include <ctype.h>
#define MAX 10
#define NUM 1

// Упр.5.6 
// переписать программы через указатели

int mygetline(char *s, int max);
void itoa(char *s, int n);
void reverse(char *s, char *e);
int atoi(char *s);
int strindex(char *s, char *t);
int getop(char *s);

int getch(void);
void ungetch(int c);

int main(void) {
	char s[] = "Just a stop please";
	char t[] = "stop";
	// char s[] = "hello";
	// char t[] = "lo";
	printf("%d\n", strindex(s, t));

	char str[MAX];
	getop(str);
	printf("%s\n", str);
	 
	return 0;
}

int mygetline(char *s, int max) {
	int i, c;

	for (i = 0; i < max - 1; i++) {
		if ((c = getchar()) != EOF && c != '\n') {
			*s++ = c;
		} else {
			break;
		}
	}

	if (c == '\n') {
		*s++ = '\n';
		// для нулевого символа
		++i;
	}

	*s = '\0';

	return i;
}

void itoa(char *s, int n) {
	// здесь указатель на нулевой элемент массива
	char *p = s;
	
	char sign = 0;
	
	if (n < 0) {
		sign = 1;
		n = -n;
	}

	do {
		*s++ = n % 10 + '0';
	} while ((n /= 10) > 0);

	if (sign) {
		*s++ = '-';
	}

	// указывает на элемент массива с символом конца строки
	*s = '\0';
		
	reverse(p, --s);
	
}

// 543\0
// 345\0

void reverse(char *s, char *e) {	
	
	while (s < e) {
		int c = *s;
		*s = *e;
		*e = c;
		
		++s;
		--e;
	}
}

int atoi(char *s) {

	int sign, res;

	while (isspace(*s)) {
		++s;
	}

	sign = *s == '-' ? -1 : 1;

	if (*s == '-' || *s == '+') {
		++s;
	}

	for (res = 0; isdigit(*s); ++s) {
		res = res * 10 + (*s - '0');
	}

	return sign * res;
}

// hello\0
// lo\0

// char s[] = "Just a stop please";
// char t[] = "stop\0";

int strindex(char *s, char *t) {

	char *p = t;

	int i, count;

	i = count = 0;

	// на случай псевдопохожей строки t
	while (*s != '\0') {
		// пропускаем символы до первого соответствия
		while (*s != *t) {
				++s;
				++i;
			}
		// при соответствии считаем кол-во соответств. символов
		while (*s == *t) {
			// если t закончилась, возвращаем индекс s - кол-во символов t
			// условие нужно, чтобы не перешагнуть нулевой символ в t, когда они совпадают у s и t
			if (*t == '\0') {
				return i - count;
			}
			
			++i;
			++count;
			
			++s;
			++t;
		}

		// если t закончилась, возвращаем индекс s - кол-во символов t
		// иначе возвращаем указатель t в начало и зануляем счетчик прочитанных t символов
		// условие нужно, когда символ конца строки в t не соответсвует символу конца строки в s
		if (*t == '\0') {
			return i - count;
		} else {
			t = p;
			count = 0;
		}
	
	}
	
	return -1;
}

int getop(char *s) {
	int c;

	while (isspace(*s = c = getch()));
	*++s = '\0';

	if (!isdigit(c) && c != '.') {
		return c;
	}

	if (isdigit(c)) {
		while (isdigit(*s++ = c = getch()));
	}

	if (c == '.') {
		while (isdigit(*s = c = getch())) {
			++s;
		}
	}

	*s = '\0';

	if (c != EOF) {
		ungetch(c);
	}

	return NUM;
}

char buf[MAX];
int i = 0;

int getch(void) {
	return i > 0 ? buf[--i] : getchar();
}

void ungetch(int c) {
	if (i < MAX) {
		buf[i++] = c;
	} else {
		printf("error");
	}
}
