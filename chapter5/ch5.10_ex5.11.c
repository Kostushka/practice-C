#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Упр. 5.11 
// Усовершенствовать программы detab и entab 
// так, чтобы они принимали в качетсве аргументов командной строки список позиций tab

void detab(int tab, int pos);
void entab(int tab, int pos);

int main(int argc, char *argv[]) {

	char s[] = "      ";

	int c, pos;

	pos = 0;

	while ((c = getchar()) != EOF) {
		if (c != '\n' && c != '\t') {
			++pos;
			putchar(c);
		} else if (c == '\n') {
			pos = 0;
			putchar(c);
		} else {
			if (argc != 2) {
				detab(4, pos);
			} else {
				detab(atoi(argv[1]), pos);
			}
		}
	}

	if (argc != 2) {
		entab(4, strlen(s));
	} else {
		entab(atoi(argv[1]), strlen(s));
	}

	return 0;
}

// h\t 
// "h   "
void detab(int tab, int pos) {
	int space;

	space = tab - (pos % tab);

	while (space--) {
		putchar(' ');
	}
}

// "      "
// "\t\t  "
void entab(int tab, int pos) {
	int t, sp;
	t = pos / tab;
	sp = pos % tab;
	while (t-- > 0) {
		putchar('\t');
	}
	while (sp-- > 0) {
		putchar(' ');
	}
		
}
