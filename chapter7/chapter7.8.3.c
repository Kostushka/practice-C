#include <stdio.h>

// 7.8.3 Функция ungetc

// помещает символ с назад в файл 
int ungetc (int c, FILE *fp);

int main (void) {
	FILE *fp;
	ungetc('c', fp);
	return 0;
}
