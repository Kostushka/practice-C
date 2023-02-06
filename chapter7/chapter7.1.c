#include <stdio.h>
#include <ctype.h>
// 7.1 Стандартные средства ввода - вывода
// gcc chapter7.1.c && ./a.out < infile - берем вводные данные из файла
// cat infile | ./a.out - вывод команды cat перенаправляем на ввод программы
// ./a.out < infile > outfile - программа берет вводные данные из файла и перенапрявляет вывод данных в файл

// int mytolower (int c);

int main (void) {
	int c;
	while ((c = getchar()) != EOF) {
		putchar(tolower(c));
	}
	return 0;
}


// int mytolower (int c) {
	// if (c > 'A' && c < 'Z') {
		// return c + ('a' - 'A');
	// }
	// return c;
// }
