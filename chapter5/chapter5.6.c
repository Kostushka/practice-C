#include <stdio.h>
#define MAX 5000 // максимальное количество строк
#define MAXLEN 1000 // максимальная длина строки из входного потока

// 5.6 Массивы указателей и указатели на указатели
// Указатель - переменная, поэтому ее можно хранить в массиве

// Задача: отсортировать строки в алфавитном порядке
// 1) взять указатели на начало строк
// 2) поместить указатели в массив
// 3) сравнить две строки, используя функцию strcmp
// 4) чтобы строки поменять местами - меняем местами указатели в массиве

// Этапы
// считать все строки с входного потока
// отсортировать строки
// вывести в отсортированном порядке

// массив указателей для строк
char *strp[MAX];

char buf[MAX];
char *bufi = buf; // указатель на след. свободный элемент

int mygetline (char *s);
int mystrcmp (char *s, char *t);
void swap (char *v[], int i, int j);
char* alloc (int a);
int readlines (void);
void qsort (char *strp[], int start, int end);
void writeline (int n);

int main (void) {

	int n; // кол-во строк

	// если возвращенное значение положительно
	// сортируем и выводим на печать
	if ((n = readlines()) >= 0) {
		qsort(strp, 0, n - 1);
		writeline(n);
		return 0;
	// иначе ошибка: превышен лимит строк
	} else {
		printf("Error: too match srings");
		return 1;
	}

	return 0;
}

int mygetline (char *s) {
	int c, i;
	i = 0;
	while (i++ < MAXLEN - 1) {
		if ((c = getchar()) != EOF && c != '\n') {
			*s++ = c;
		} else {
			break;
		}
	}
	if (c == '\n') {
		*s++ = c;
	}
	*s = '\0';
	
	return i;
}

int mystrcmp (char *s, char *t) {
	while (*s == *t) {
		if (*s == '\0') {
			return 0;
		}
		++s;
		++t;
	}
	return *s - *t;
}

char* alloc (int a) {
	// есть место для строки
	if (buf + MAX - bufi >= a) {
		bufi += a;
		return bufi - a;
	// нет места для строки
	} else {
		return 0;
	}
}

void qsort (char *strp[], int start, int end) {
	int pivot, i;
	if (start >= end) {
		return;
	}
	swap(strp, start, (start + end) / 2);
	pivot = start;
	for (i = start + 1; i <= end; i++) {
		if (mystrcmp(strp[start], strp[i]) > 0) {
			swap(strp, ++pivot, i);
		}
	}
	swap(strp, pivot, start);
	qsort(strp, start, pivot - 1);
	qsort(strp, pivot + 1, end);
}

// меняем местами указатели
void swap (char *v[], int i, int j) {
	char *p;
	p = v[i]; // берем указатель из массива по индексу
	v[i] = v[j]; 
	v[j] = p;
}
