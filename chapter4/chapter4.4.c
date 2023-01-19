#include <stdio.h>
#define MAX 100

// 4.4 Область действия (видимости) - часть программы, в пределах которой можно использовать имя переменной/функции
// Область видимости внешней переменной или функции: от точки объявления до конца компилируемого файла

// file2
// объявление переменных - память не выделяется
// объявление, действительное до конца файла
extern int i;
extern double stack[];

int main (void) {

	printf("%d\n", i);

	return 0;
}

// file1
// определение внешних переменных - выделение памяти
// объявление, действительное до конца файла
int i = 0;
double stack[MAX];

