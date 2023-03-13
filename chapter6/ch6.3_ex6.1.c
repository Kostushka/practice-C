#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define NKEY (int)(sizeof keytab / sizeof keytab[0])
#define MAX 100

struct Key {
	char *word;
	int count;
} keytab[] = {
	{"continue", 0},
	{"double", 0},
	{"float", 0},
	{"int", 0},
	{"main", 0},
	{"return", 0},
	{"struct", 0},
	{"void", 0},
};

int getword(char *s, int max);
int binsearch(char *w, struct Key keytab[], int n);
int getch(void);
void ungetch(int c);

int main(void) {

	char s[MAX];
	int n;

	while(getword(s, MAX) != EOF) {
		if (isalpha(s[0])) {
			if ((n = binsearch(s, keytab, NKEY)) >= 0) {
				keytab[n].count++;
			}
		}
		
	}
	
	for (n = 0; n < NKEY; n++) {
		printf("%d %s\n", keytab[n].count, keytab[n].word);
	}
	
	return 0;
}

int binsearch(char *w, struct Key keytab[], int n) {
	int low = 0;
	int high = n - 1;
	int con;
	while (low <= high) {
		int mid = (low + high) / 2;
		if ((con = strcmp(w, keytab[mid].word)) == 0) {
			return mid;
		} else if (con < 0) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}

	return -1;
}

int getword(char *s, int max) {
	int c;
	char *w = s;

	while (isspace(c = getch()));

	if (c != EOF) {
		*s++ = c;
	}

	if (!isalpha(c)) {
		*s = '\0';
		return c;
	}

	for (; --max > 0; s++) {
		if (!isalpha(*s = getch())) {
			ungetch(*s);
			break;
		}
	}
	
	*s = '\0';
	
	return *w;
}

char buf[MAX];
int i = 0;

int getch(void) {
	return i > 0 ? buf[--i] : getchar();
}

void ungetch(int c) {
	if (i < MAX) {
		buf[i++] = c;
	}
}
