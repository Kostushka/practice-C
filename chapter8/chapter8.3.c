#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#define PERMS 0666

// 8.3 Функции open, creat, close, unlink

// чтобы открыть файл, нужны вызовы open и creat
// open возвращает файловый дескриптор
// int open(char *name, int flags, int perms);

// name - символьное имя файла
// flags - способ открытия файла (O_RDONLY O_WRONLY O_RDWR)
// perms - набор допусков (9 битов)
// fd - файловый дескриптор
// int fd;
// fd = open(name, O_RDONLY, 0); // открыть только для чтения

// creat создает файл или перезаписывает существующий (усекает до нулевой длины)
// int creat(char *name, int perms);
// fd = creat(name, perms);

// удаляет имя файла из файловой системы
// unlink(char *name)

void error(char *, ...);

// cp: копирует один файл в другой f1 в f2
int main (int argc, char *argv[]) {
	int f1, f2, n;
	char buf[BUFSIZ];

	if (argc != 3) {
		error("You should use 3 argc");
	}
	if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
		error("can't open %s", argv[1]);
	}
	if ((f2 = creat(argv[2], PERMS)) == -1) {
		error("can't create %s, mode %030", argv[2], PERMS);
	}
	while ((n = read(f1, buf, BUFSIZ)) > 0) {
		if (write(f2, buf, n) != n) {
			error("write error of file %s", argv[2]);
		}
	}
	return 0;
}

void error(char *fmt, ...) {
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");

	va_end(args);
	exit(1);
}
