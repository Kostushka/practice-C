#include <stdio.h>
#include <unistd.h>

// 8.2 Ввод-вывод низкого уровня - функции read и write
// при вводе-выводе используются системные вызовы read и write
// 3 аргумента: 1) дескриптор файла
// 				2) символьный массив, в котор или из котор поступают данные
// 				3) кол-во байт, которые необходимо переслать

// n_read и n_written - кол-во переданных байт, 0 - если конец файла, -1 - если ошибка
// int n_read = read(int fd, char *buf, int n);
// int n_written = write(int fd, char *buf, int n);

// mygetchar: небуферизированный ввод одного символа
int mygetchar(void);

// mygetchar2: с простой буферизацией ввод одного символа
int mygetchar2(void);

int main (void) {
	char buf[BUFSIZ];
	int n; // сколько байт прочитано
	
	// дескриптор входного потока
	while ((n = read(0, buf, BUFSIZ)) > 0) {
	
		printf("%d %d\n", BUFSIZ, n);
		
		// дескриптор выходного потока
		write(1, buf, n);
	}

	// char c;
// 
	// while((c = mygetchar2()) != EOF) {
		// printf("%c\n", c);
	// }
	
	return 0;
}

int mygetchar(void) {
	char c;
	// прочитали 1 символ - вернули
	return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}

int mygetchar2(void) {
	static char buf[BUFSIZ];
	static char *bufp = buf;
	static int n = 0;
	if (n == 0) { // буфер пуст
		n = read(0, buf, sizeof buf);
		bufp = buf;
	}
	return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}
