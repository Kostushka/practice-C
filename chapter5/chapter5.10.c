#include <stdio.h>
#include <string.h>
#define MAX 100

// 5.10 Аргументы командной строки
// программа echo - выводит свои аргументы в одной строке через пробел
// два аргумнта: argc - argument count - счетчик аргументов
// 				 argv - argument vector - вектор аргуменов (массив строк с аргументами)
// argv[0]: имя программы 
// argc: 1 (всегда не меньше 1)

// echo hello world
// argc: 3 => [0, 1, 2]
// argv[0]: "echo", argv[1]: "hello", argv[2]: "world"

// echo версия 1 
// int main (int argc, char *argv[]) {
// 
	// int i;
	// 
	// for (i = 1; i < argc; i++) {
		// printf("%s%s ", argv[i], (i < argc - 1) ? " " : "");
	// }
	// printf("\n");
	// 
	// return 0;
// }

// echo версия 2: через argv как указатель на массив указателей
// int main (int argc, char *argv[]) {
// 
	// while (--argc > 0) {
		// printf("%s%s ", *++argv, (argc > 1) ? " " : "");
	// }
	// printf("\n");
	// 
	// return 0;
// }

int mygetline (char *s);

// find: вывод строк, содержащих образец из 1-ого аргумента
int main (int argc, char *argv[]) {

	char s[MAX];
	// мы должны получить два аргумента: "main", "..."
	if (argc != 2) {
		printf("Input correct value\n");
	} else {
		while (mygetline(s) > 0) {
			// strstr - возвращает указатель на первую найденную подстроку t в s
			if (strstr(s, argv[1]) != NULL) {
				// печатаем строку, в которой есть подстрока
				printf("%s", s);
			}
		}
	}
	
	return 0;
}

int mygetline (char *s) {
	int i, c;
	for (i = 0; i < MAX - 1; i++) {
		if ((c = getchar()) != EOF && c != '\n') {
			*s++ = c;
		} else {
			break;
		}
	}

	if (c == '\n') {
		*s++ = c;
	}
	*s = '\0';
	
	return i;
}

// необязательные параметры пишутся через "-"
// -x - дейсвтия обратные алгоритму (выводить строки, в которых нет подстроки)
// -n - выводить порядковый номер строки
// find -x -n
// find -nx
