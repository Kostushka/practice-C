#include <stdio.h>
#define TAB 8

// Упр. 1.20
// Программа заменяет символы tab во входном потоке пробелами до следующей границы

// граница табуляции 4
/*
   4   8   12
123456789abcdef
*/

void detab(int width, int pos);

int main(void) {
	int c, n;

	n = 0;

	while((c = getchar()) != EOF) {
		if (c != '\t' && c != '\n') {
			putchar(c);
			++n;
		} else if (c == '\n') {
			putchar(c);
			n = 0;
		} else {
			detab(TAB, n);
		}
	}
	
	return 0;
}
/*
9 / 4 = 2 tab 
2 * 4 = 8 width tab
9 - 8 = 1 занято места от ближайшей границы
или
9 % 4 = 1 занято места от ближайшей границы

4 - 1 = 3 пробела

123456789
*/

// width - ширина tab 
// pos - номер позиции
void detab(int width, int pos) {
	int p = width - (pos % width);
	
	for (; p != 0; p--) {
		putchar(' ');
	}
}
