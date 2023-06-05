#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX 100
#define MAXLEN 100

// Упр. 8.1
// Программа cat с использованием системных вызовов read, write, open, close ??

void filecpy(int in, int out);

// cat - выводит содержимое файла в другой файл
int main(int argc, char *argv[]) {
	int f1, f2;
	
	if (argc == 1) {
		// дескрипторы stdin, stdout
		filecpy(0, 1);
	}
	if (argc == 3) {
		// дескриптор первого файла
		if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
			printf("error, can't read %s\n", argv[1]);
			return 1;
		}
		// дескриптор второго файла
		if ((f2 = creat(argv[2], 0666)) == -1) {
			printf("error, can't write %s\n", argv[2]);
			return 1;
		}
		filecpy(f1, f2);
	} else if (argc == 2) {
		if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
			printf("error, can't read %s\n", argv[1]);
			return 1;
		}
		filecpy(f1, 1);
	} 
	
	return 0;
}

void filecpy(int in, int out) {
	char buf[BUFSIZ];
	int n;

	while ((n = read(in, buf, BUFSIZ)) > 0) {
		write(out, buf, n);
	}
}
