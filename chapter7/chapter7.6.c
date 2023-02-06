#include <stdio.h>
#include <stdlib.h>
// 7.6 Обработка ошибок. Поток stderr и функция exit
// когда программа запускается на исполнение, OS открывает 3 файла и создает указатели на них:
// stdin
// stdout
// stderr - стандартный поток ошибок

// int ferrof (FILE *fp) возвращает не ноль, если произошла ошибка в потоке fp
// int feof (FILE *fp) возвращает не ноль, если достигнут конец файла

void filecopy (FILE *, FILE *);

// cat со стандартным потоком ошибок
int main (int argc, char *argv[]) {
	FILE *fp;
	char *prog = argv[0]; // имя программы
	if (argc == 1) {
		filecopy(stdin, stdout);
	} else {
		while (--argc > 0) {
			if ((fp = fopen(*++argv, "r")) == NULL) {
				// посылает ошибку в файл stderr
				fprintf(stderr, "%s: can't open: %s\n", prog, *argv);
				// прекращает работу программы
				// аргумент доступен процессу, запустившему программу
				// вызывает fclose для закрытия каждого открытого файла и очищения буфера вывода
				exit(1);
			} else {
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	if (ferror(stdout)) {
		// посылает ошибку в файл stderr
		fprintf(stderr, "%s: error stdout", prog);
		exit(2);
	}
	
	exit(0);
}

void filecopy (FILE *in, FILE *out) {
	int c;
	while ((c = getc(in)) != EOF) {
		putc(c, out);
	}
}
