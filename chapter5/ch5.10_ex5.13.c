#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

// Упр. 5.13
// tail - вывод последних n строк входного потока
// tail -n

int tail(void);
char *alloc(int a);
void mystrcpy(char *s, char *t);
int mygetline(char *s, int max);

char *lines[MAX];

int main(int argc, char *argv[]) {

	int n;

	if (argc == 2) {
		n = *++argv[1] - '0';
	} else {
		n = 3;
	}
	
	int i = tail();
	--i;
	i = i - n + 1;

	if (i >= 0) {
		while (n-- > 0) {
			printf("%s\n", lines[i++]);
		}
	} else {
		printf("not enough string\n");
	}

	return 0;
}

char buf[MAX];
char *i = buf;

char *alloc(int a) {
	if (buf + MAX - i >= a) {
		i += a;
		return i - a;
	}
	
	return NULL;
}

int tail(void) {
	char s[MAX];
	int len, n;
	char *p;

	n = 0;
	
	while ((len = mygetline(s, MAX)) > 0) {
		if ((p = alloc(len + 1)) != NULL && n < MAX) {
			mystrcpy(p, s);
			lines[n++] = p;
		} else {
			return -1;
		}
	}

	return n;
}

void mystrcpy(char *s, char *t) {
	while ((*s = *t) != '\0') {
		++s;
		++t;
	}
}

int mygetline(char *s, int max) {
	int c, i;

	for (i = 0; i < max - 1; i++) {
		if ((c = getchar()) != EOF && c != '\n') {
			*s++ = c;
		} else {
			break;
		}
	}

	*s = '\0';

	return i;
}
