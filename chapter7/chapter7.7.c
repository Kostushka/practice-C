#include <stdio.h>
#include <string.h>
#define MAXLINE 100

// 7.7 Ввод-вывод строк
// fgets - считывает строку(с сиволом конца строки) из файла в массив символов
// char *fgets (char *line, int maxline, FILE *fp)

// fputs - записывает строку в файл
// int fputs (char *line, FILE *fp);

// тоже самое только с stdin stdout
// gets() - удаляет завершающий символ \n
// puts() - добавляет завершающий символ \n

int mygetline (char *line, int maxline);
char *myfgets (char *line, int maxline, FILE *fp);
int myfputs (char *line, FILE *fp);

int main (void) {
	char line[MAXLINE];
	printf("%d %s\n", mygetline(line, MAXLINE), line);
	
	return 0;
}

char *myfgets (char *line, int maxline, FILE *fp) {
	register int c;
	register char *s;
	s = line;
	while (--maxline > 0 && (c = getc(fp)) != EOF) {
		if ((*s++ = c) == '\n') {
			break;
		}
	}
	*--s = '\0';
	return (c == EOF && s == line) ? NULL : s;
}

int myfputs (char *line, FILE *fp) {
	int c;
	while (c = *line++) {
		putc(c, fp);
	}
	return ferror(fp) ? EOF : 0;
} 

int mygetline (char *line, int maxline) {
	if (myfgets(line, maxline, stdin) == NULL) {
		return 0;
	} else {
		return strlen(line);
	}
}
