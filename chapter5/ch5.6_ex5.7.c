#include <stdio.h>
#include <string.h>
#define MAX 5000 // максимальное количество строк
#define MAXLEN 1000 // максимальная длина строки из входного потока

// Упр. 5.7
// переписать readlines так, чтобы строки помещались в массив в main без alloc

char *strp[MAX];

int mygetline (char *s);
int mystrcmp (char *s, char *t);
void mystrcpy (char *p, char *s);
void swap (char *v[], int i, int j);
int readlines (char *buf);
void qsort (char *strp[], int start, int end);
void writeline (int n);

int main (void) {
	int n; // кол-во строк
    char bufline[MAX];

	if ((n = readlines(bufline)) >= 0) {
		qsort(strp, 0, n - 1);
		writeline(n);
		return 0;
	} else {
		printf("Error: too match srings");
		return 1;
	}

	return 0;
}

int mygetline (char *s) {
	int c, i;
	i = 0;
	while (i < MAXLEN - 1) {
		if ((c = getchar()) != EOF && c != '\n') {
			*s++ = c;
			++i;
		} else {
			break;
		}
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

int readlines (char *buf) {
	int len, nlines;
	char line[MAXLEN];
	char *p = buf;

	nlines = 0;
	while ((len = mygetline(line)) > 0) {
		// +1 для нулевого символа
		++len;
		if (buf + MAX - p >= len && nlines < MAX) {
			p += len;
			mystrcpy(p - len, line);
			strp[nlines++] = p - len;
		} else {
			return -1;
		}
	}
	return nlines;
}

void writeline (int n) {
	for (int i = 0; i < n; i++) {
		printf("%s\n", strp[i]);
	}
}

void mystrcpy (char *p, char *s) {
	while ((*p = *s) != '\0') {
		++p;
		++s;
	}
}
