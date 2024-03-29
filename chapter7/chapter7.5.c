#include <stdio.h>

// 7.5 Доступ к файлам
// программа cat - выполняет конкатенацию файлов и выводит либо в стандартный поток, либо на вход в другую программу
// cat x.c y.c

// перед чтением, файл надо открыть:
// fopen - возвращает указатель на структуру с инфо о файле (FILE - имя структуры из библиотеки)

// FILE *fp;  указатель на структуру
// FILE *fopen (char *, char *);  функция, котор. возвращает указатель на структуру
// fp = fopen(name, mode);  имя + режим открытия: чтение, запись (стирает содержимое), добавление в конец файла
void writefile (void) {
	int c;
	FILE *fp = fopen("file", "a");
	while ((c = getc(stdin)) != EOF) {
		putc(c, fp);
	}	
	fprintf(fp, "%s", "text\n");
}

// int fclose(FILE *fp); разрывает связь между именем и файловым указателем, освобождая указатель для другого файла
// int getc(FILE *fp); - возвращает символ из файла или EOF
// int putc(int c, FILE *fp); - записывает символ в файл и возвращает записанный символ или EOF

// копируем из стандартного входа в стандартный вывод
void filecopy (FILE *in, FILE *out);

int main (int argc, char *argv[]) {
	writefile();
	
	FILE *fp;
	// если нет аргументов
	if (argc == 1) {
		// копируем из стандартного входа в стандартный вывод
		filecopy(stdin, stdout);
	} else {
		while (--argc > 0) {
			// если указатель на структуру с инфо о файле - NULL
			if ((fp = fopen(*++argv, "r")) == NULL) {
				printf("Not such file as %s\n", *argv);
				return 1;
			} else {
				// копируем из указателя в стандартный вывод
				filecopy(fp, stdout);
				fclose(fp);
			}
		}
	}
	return 0;
}

void filecopy (FILE *in, FILE *out) {
	int c;
	while ((c = getc(in)) != EOF) {
		putc(c, out);
	}
}
