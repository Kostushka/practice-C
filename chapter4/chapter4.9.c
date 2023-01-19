#include <stdio.h>

// 4.9 Инициализация
// при отсутствии инициализации:
// - глобальные и статические переменные инициализируются неявно 0 - инициализация один раз до начала выполнения программы
// - автоматические и регистровые переменные инициализируются неявно мусором - инициализация на каждом входе в блок

// ноль
int y;
static int y2;

int main (void) {

	 // мусор
	 int x;
	 register int x2;
	 // ожидаем мусор и ноль
	 printf("x: %d x2: %d y: %d y2: %d\n", x, x2, y, y2);

	 // инициализация массива
	 int days[] = {1, 2, 3, 4, 5, 6};

	 int a[10] = {1, 2, 3, 4}; // [1 2 3 4 0 0 0 0 0 0]
	 for (int i = 0; i < 10; i++) {
	 	printf("%d\n", a[i]);
	 } 

	 char s[] = "hello";
	 char s2[] = {'h', 'e', 'l', 'l', 'o', '\0'}; 
	 printf("%s %s\n", s, s2);
	 
	 return 0;
}
