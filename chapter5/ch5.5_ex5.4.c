#include <stdio.h>

// Упр. 5.4
// strend возвращает 1, если строка t присутствует в конце строки s
// иначе 0

int strend (char *s, char *t);

int main (void) {
	char s[] = "message";
	char t[] = "sage";
	printf("%d\n", strend(s, t));
	return 0;
}

int strend (char *s, char *t) {
	// записать адрес в переменную
	char *p = t;

	// дойти до \0 в обеих строках
	while (*s != '\0') {
		++s;
	}
	while (*t != '\0') {
		++t;
	}
	// пока символы, начиная с последнего, равны
	while (*--s == *--t) {
		// если дошли до начала второй строки, 
		// т.е когда адрес t равен адресу t, записанному в переменную
		if (t == p) {
			return 1;
		}
	}
	
	return 0;	
}
