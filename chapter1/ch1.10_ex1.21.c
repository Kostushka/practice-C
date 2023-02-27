#include <stdio.h>
#include <string.h>
#define LIM 100
#define TAB 4

// entab - заменяет пустые строки строками из минимального кол-ва tab + пробелов, заполняющих в сумме то же пространство
// "                  "
// tab tab _ _

// void entab(int width, int pos);
void entab(int width, char s[]);
int mygetline(char s[], int max);

int main(void) {
	char s[LIM];
	int len;
	while ((len = mygetline(s, LIM)) > 0) {
		--len;
		while (s[len] == ' ') {
			if (len == 0) {
				entab(TAB, s);
			}
			--len;
		}
		printf("%s\n", s);
	}
	return 0;
}

int mygetline(char s[], int max) {
	int c, i;
	for (i = 0; i < max - 1; i++) {
		if ((c = getchar()) != EOF && c != '\n') {
			s[i] = c;
		} else {
			break;
		}
	}
	
	s[i] = '\0';
	
	return i;
}
//  12345678
// "        "
// 9 / 4 = 2 tab
// напечатать tab
// 9 - (2 * 4) = 1 сколько символов от последней границы табуляции
// 4 - 1 = 3
// или
// 4 - (9 % 4) = 3 сколько пробелов нужно до следующей границы tab

void entab(int width, char s[]) {
	int tab, k, sp;

	k = 0;
	for (tab = strlen(s) / width; tab > 0; tab--) {
		s[k++] = '\t';
	}

	// sp = strlen(s) - ((strlen(s) / width) * width);
	
	sp = strlen(s) % width; // сколько символов от последней границы tab

	while (sp > 0) {
		s[k++] = ' ';
		--sp;
	} 
	
	s[k] = '\0';
}
