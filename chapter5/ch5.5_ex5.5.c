#include <stdio.h>
// Упр. 5.5 
// strncpy с указателями - обрабатывает не более n первых символов строковых аргументов
// strncat
// strncmp

// копирует не более n символов строки t в строку s
void mystrncpy (char *s, char *t, int n);

// копирует строку t в конец строки s не более n символов
void mystrcat (char *s, char *t, int n);

// сравнивает строки s и t до первого отличного символа не более n символов
int mysrtncmp (char *s, char *t, int n);

int main (void) {
	char s[] = "Hello ";
	char t[] = "world";
	mystrncpy(s, t, 2);
	printf("%s\n", s);

	char s2[] = "Hello ";
	char t2[] = "world";
	mystrcat(s2, t2, 3);
	printf("%s\n", s2);

	char s3[] = "Hello ";
	char t3[] = "Helo";
	printf("%d\n", mysrtncmp(s3, t3, 4));
	return 0;
}

void mystrncpy (char *s, char *t, int n) {

	while (n) {
		*s = *t;
		if (*s == '\0') {
			return;
		}
		++s;
		++t;
		--n;
	}
	*s = '\0';
	
}

void mystrcat (char *s, char *t, int n) {

	while (*s != '\0') {
		++s;
	}
	
	while (n) {
		*s = *t;
		if (*s == '\0') {
			return;
		}
		++s;
		++t;
		--n;
	}
	*s = '\0';
	
}

int mysrtncmp (char *s, char *t, int n) {

	while (*s == *t && n) {
	
		if (*s == '\0') {
			return 0;
		}
		--n;
		++s;
		++t;
	}

	if (n <= 0) {
		return 0;
	}

	return *s - *t;
}
