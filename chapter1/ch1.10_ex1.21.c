#include <stdio.h>
#define LIM 100

// entab - заменяет пустые строки строками из минимального кол-ва tab + пробелов, заполняющих в сумме то же пространство
// "                  "
// tab tab _ _

void entab(int max, char s[]);

int main(void) {
	char s[] = "           ";
	entab(4, s);
	return 0;
}

void entab(int max, char s[]) {
	int n, i, j;
	char s2[LIM];
	
	n = j = 0;
	
	for (i = 0; s[i] != '\0'; i++) {
		if (n == max) {
			while (max-- > 0) {
				s2[j++] = ' ';
			}
			n = 0;
			continue;
		}
		++n;
	}
	if (n > 0) {
		while (n-- > 0) {
			s2[j++] = ' ';
		}
	}

	s2[j] = '\0';

	printf("%s", s2);
	
}
