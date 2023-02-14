#include <stdio.h>
#define TAB 10

// замена \t 4 пробелами
// h - 3 пробела
// hh - 2 пробела
// hhh - 1 пробел
// hhhh и больше - 4 пробела

void detab(int max, int n);

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
		
		// if (c != '\t' && c != '\n') {
			// putchar(c);
			// ++n;
		// } else if (c == '\n') {
			// putchar(c);
			// n = 0;
		// } else {
			// switch(n) {
				// case 1:
					// putchar(' ');
					// putchar(' ');
					// putchar(' ');
					// break;
				// case 2:
					// putchar(' ');
					// putchar(' ');
					// break;
				// case 3:
					// putchar(' ');
					// break;
				// default:
					// putchar(' ');
					// putchar(' ');
					// putchar(' ');
					// putchar(' ');
					// break;
			// }
			// n = 0;
		// }
	}
	
	return 0;
}

// max
// 5 - 0 = 5
// 5 - 1 = 4
// 5 - 2 = 3
// 5 - 3 = 2
// 5 - 4 = 1
// 5 - 5 = 0
// 5 - 6 = -1
// max пробелов - n символов > 0 ? печатаем max - n пробелов : печатаем max пробелов
void detab(int max, int n) {
	int sp;
	
	if ((sp = (max - n)) > 0) {
		while (sp-- > 0) {
			putchar(' ');
		}
	} else {
		while (max-- > 0) {
			putchar(' ');
		}
	}
}
