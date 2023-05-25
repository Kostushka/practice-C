#include <stdio.h>
#include <ctype.h>
#define MAX 10
// 5.2 Указатели и аргументы функций

void swap (int a, int b);
void swap2 (int *, int *);

int getint(int *);
int getch (void);
void ungetch (int c);

int main (void) {
	// вызываем функцию для получения чисел из входного потока
	// числа записываем в массив с ячейками для каждого числа
	int numbers[MAX], i;
	// int *p = numbers;
	// for (i = 0; i < MAX && getint(p) != EOF; p++) {
		// printf("%d: %d\n", i, numbers[i]);
		// ++i;
	// }
	for (i = 0; i < MAX && getint(&numbers[i]) != EOF; i++) {
		printf("%d: %d\n", i, numbers[i]);
	}

	int x = 23, y = 67;
	printf("%d %d\n", x, y);
	
	swap(x, y); // аргументы передаются по значению
	printf("нет изменений\n");
	printf("%d %d\n", x, y);
	
	swap2(&x, &y); // передаем адреса
	printf("поменяли местами\n");
	printf("%d %d\n", x, y);
	
	return 0;
}

// НЕПРАВИЛЬНО
void swap (int a, int b) {
	// здесь меняются локальные переменные
	int c;
	c = a;
	a = b;
	b = c;
}

// ПРАВИЛЬНО
void swap2 (int *a, int *b) {
	// работаем с указателями (адресами)
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

// получить целое число из входного потока
int getint (int *p) {
	int c, sign;
	
	// пропускаем пробелы
	while (isspace(c = getch()));

	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		// бесконечный цикл, если знак не пробельный
		// по умолчанию в массиве всякая ерунда
		ungetch(c); // не цифра
		return 0;
	}
	
	// запомниаем и пропусаем знак
	sign = c == '-' ? -1 : 1;
	if (c == '-' || c == '+') {
		c = getch();
	}

	// записываем по адресу число
	for (*p = 0; isdigit(c); c = getch()) {
		*p = *p * 10 + (c - '0');
	}
	*p *= sign;

	// если не конец файла запоминаем
	if (c != EOF) {
		ungetch(c);
	}
	// для того, чтобы иметь возможность вернуть EOF
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
