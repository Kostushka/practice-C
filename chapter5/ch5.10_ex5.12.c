#include <stdio.h>

// Упр. 5.12
// entab и detab, понимающие запись 
// entab -m +n - вставить tab каждые n столбцов, начиная с m

void detab(int tab, int pos);

int main(int argc, char *argv[]) {

	int pos, width, c;
	// pos = 0;
	// while ((c = getchar()) != EOF) {
		// if (c != '\t' && c != '\n') {
			// ++pos;
			// putchar(c);
		// } else if (c == '\n') {
			// pos = 0;
			// putchar(c);
		// } else {
			// 
		// }
	// }

	if (argc != 1) {
		switch ((*++argv)[0]) {
			case '-':
				pos = *++argv[0];
				break;
			case '+':
				width = *++argv[0];
				break;
		}
		detab(width, pos);
	} else {
		detab(4, pos);
	}
}

// 12345678
// 12345\t
// 12345...

void detab(int tab, int pos) {
	int sp = tab - (pos % tab);
	
	while (sp-- > 0) {
		putchar(' ');
	}
}
